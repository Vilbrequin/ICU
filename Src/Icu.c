/****************************************************************************************************/
/*                                      Includes                                                    */
/****************************************************************************************************/
#include "Icu.h"
#include "Det.h"
#include "EcuM.h"
#include "Icu_Regs.h"

#define CnSC_OFFSET(channel) (0x0C + ((channel) * 0x08))
#define CnV_OFFSET(channel) (0x10 + ((channel) * 0x08))

#define PCC_CGC_MASK                    (1 << 30)
#define MODE_WPDIS_MASK                 (1 << 2)
#define MODE_FTMEN_MASK                 (1 << 0)
#define COMBINE_ICU_MODE_MASK           (0x85858585 << 0)
#define SC_CPWMS_MASK                   (1 << 5)
#define SC_TOIE_MASK                    (1 << 8)
#define SC_CLKS_DISABLE_MASK            (3 << 3)
#define SC_FLTPLS_MASK                  (0x0F << 24) // to clear the FLTPS bits
#define SC_PS_MASK                      (0x07 << 0) // to clear the PS bits 
#define CnSC_MSB_MSA_MASK               (3 << 4)
#define CnSC_CHIE_MASK                  (1 << 6)

#define SC_RESET_MASK                   0x0FFF017FU
#define CNT_RESET_MASK                  0xFFFFU
#define COMBINE_RESET_MASK              0xFFFFFFFFU
#define MOD_RESET_MASK                  0xFFFFU
#define CNTIN_RESET_MASK                0xFFFFU
#define CnSC_RESET_MASK                 0x017FU
#define MODE_RESET_MASK                 0xFFU


#define FTM_CNT_MAX_VAL                 (uint32)0xFFFF
#define FTM_CINT_VAL                    (uint32)0x0000   

// variables bellow are declared as static global variable to limite access only in the scope of this file !
static uint8 Icu_Status = ICU_NOT_INITIALIZED;
static Icu_ChannelConfigType *Icu_Channels_Config_ptr = NULL_PTR;
static uint8 Icu_NumberOf_Channels = 0;
static uint8 Ftm_Configured_Mask = 0;

static Icu_FTM_ID get_instance_id(Icu_ChannelType channelId)
{
    return (Icu_FTM_ID)channelId / CHANNELS_PER_INSTANCE;
}
static Icu_ChannelType get_Channel_id(Icu_ChannelType channelId)
{
    return (Icu_ChannelType)channelId % CHANNELS_PER_INSTANCE;
}

void Icu_Init(const Icu_ConfigType *ConfigPtr)
{
    #if (STD_ON == ICU_DEV_ERROR_DETECT)
        if((NULL_PTR == ConfigPtr) || (NULL_PTR == ConfigPtr->Icu_ChannelConfig)){
            Det_ReportError(ICU_MODULE_ID, ICU_MODULE_INSTANCE_ID, ICU_INIT_SID, ICU_E_INIT_FAILED);
            return;
        }
    #endif
    Icu_Channels_Config_ptr = ConfigPtr->Icu_ChannelConfig;
    Icu_NumberOf_Channels = ConfigPtr->Icu_NumberOfChannels;

    // Initialize register of the FTM instance
    for (uint8 i = 0; i < Icu_NumberOf_Channels; i++)
    {
        Icu_FTM_ID FtmId = get_instance_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);
        Icu_FilterPrescalerType FTM_fltr_prescaler = Icu_Channels_Config_ptr[i].Icu_FilterPrescaler;
        Icu_ClockPrescalerType FTM_clk_prescaler = Icu_Channels_Config_ptr[i].Icu_ClockPrescaler;

        volatile uint32 *pcc_address = NULL_PTR;
        volatile uint32 *ftm_mode = NULL_PTR;
        volatile uint32 *ftm_combine = NULL_PTR;
        volatile uint32 *ftm_sc = NULL_PTR;
        volatile uint32 *ftm_mod = NULL_PTR;
        volatile uint32 *ftm_cint = NULL_PTR;

        // check if the PCC of the FTM instance is alerady initialized
        if ((Ftm_Configured_Mask) & (1 << FtmId))
        {
            continue;
        }

        switch (FtmId)
        {
        case FTM_0:
            pcc_address = (volatile uint32 *)PCC_FTM_0;
            ftm_mode = (volatile uint32 *)(FTM_0_MODE);
            ftm_combine = (volatile uint32 *)(FTM_0_COMBINE);
            ftm_sc = (volatile uint32 *)(FTM_0_SC);
            ftm_mod = (volatile uint32 *)(FTM_0_MOD);
            ftm_cint = (volatile uint32 *)(FTM_0_CNTIN);
            break;
        case FTM_1:
            pcc_address = (volatile uint32 *)PCC_FTM_1;
            ftm_mode = (volatile uint32 *)(FTM_1_MODE);
            ftm_combine = (volatile uint32 *)(FTM_1_COMBINE);
            ftm_sc = (volatile uint32 *)(FTM_1_SC);
            ftm_mod = (volatile uint32 *)(FTM_1_MOD);
            ftm_cint = (volatile uint32 *)(FTM_1_CNTIN);
            break;
        case FTM_2:
            pcc_address = (volatile uint32 *)PCC_FTM_2;
            ftm_mode = (volatile uint32 *)(FTM_2_MODE);
            ftm_combine = (volatile uint32 *)(FTM_2_COMBINE);
            ftm_sc = (volatile uint32 *)(FTM_2_SC);
            ftm_mod = (volatile uint32 *)(FTM_2_MOD);
            ftm_cint = (volatile uint32 *)(FTM_2_CNTIN);
            break;
        case FTM_3:
            pcc_address = (volatile uint32 *)PCC_FTM_3;
            ftm_mode = (volatile uint32 *)(FTM_3_MODE);
            ftm_combine = (volatile uint32 *)(FTM_3_COMBINE);
            ftm_sc = (volatile uint32 *)(FTM_3_SC);
            ftm_mod = (volatile uint32 *)(FTM_3_MOD);
            ftm_cint = (volatile uint32 *)(FTM_3_CNTIN);
            break;
        default:
            // Do Nothing
            break;
        }

        // Enable the clock for the FTM instance
        *pcc_address |= PCC_CGC_MASK;

        // Disable write protection of the FTM instance
        *ftm_mode |= MODE_WPDIS_MASK;

        // Disable MCOMBINE (Modified Combine) and DECAPEN (Dual Edge Capture) and COMBINE (Combine Channels) modes
        *ftm_combine &= ~COMBINE_ICU_MODE_MASK;
        
        // Disable the FTM counter CLKS[1:0] = 0:0
        *ftm_sc &= ~SC_CLKS_DISABLE_MASK;
        
        // Set Up Counting mode for the FTM instance
        *ftm_sc &= ~SC_CPWMS_MASK;

        // FTLPS[27:24]
        *ftm_sc &= ~SC_FLTPLS_MASK; // clear the existing filter prescaler value
        *ftm_sc |= (FTM_fltr_prescaler << 24); // set the new filter prescaler value
        

        // PS[2:0]
        *ftm_sc &= ~SC_PS_MASK; // clear the existing clock prescaler value
        *ftm_sc |= (FTM_clk_prescaler << 0); // set the new clock prescaler value
        

        // Define the upper limit of the FTM counter
        *ftm_mod = FTM_CNT_MAX_VAL;

        // Define the Initial value of the FTM counter
        *ftm_cint = FTM_CINT_VAL;

        // Disable Timer Overflow Interruption of the FTM instance (SWS_Icu_00061)
        *ftm_sc &= ~SC_TOIE_MASK;

        Ftm_Configured_Mask |= (1 << FtmId);
    }

    // Initialize registers for a specifique channel
    for (uint8 i = 0; i < Icu_NumberOf_Channels; i++)
    {
        Icu_FTM_ID FtmId = get_instance_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);
        Icu_ChannelType CnId = get_Channel_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);

        volatile uint32 *ftm_cnsc = NULL_PTR;
        volatile uint32 *ftm_fltr = NULL_PTR;

        switch (FtmId)
        {
        case FTM_0:
            ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_0_BASSE_ADDRESS + CnSC_OFFSET(CnId)); // the cast to unit8* is to ensure byte-level ptr arithmitic
            ftm_fltr = (volatile uint32 *)(FTM_0_FILTER);
            break;
        case FTM_1:
            ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_1_BASSE_ADDRESS + CnSC_OFFSET(CnId));
            ftm_fltr = (volatile uint32 *)(FTM_1_FILTER);
            break;
        case FTM_2:
            ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_2_BASSE_ADDRESS + CnSC_OFFSET(CnId));
            ftm_fltr = (volatile uint32 *)(FTM_2_FILTER);
            break;
        case FTM_3:
            ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_3_BASSE_ADDRESS + CnSC_OFFSET(CnId));
            ftm_fltr = (volatile uint32 *)(FTM_3_FILTER);
            break;
        default:
            // Do Nothing
            break;
        }

        // Clear MSB:MSA bits of the CnSc register to set the input capture mode for the selected channel
        *ftm_cnsc &= ~CnSC_MSB_MSA_MASK;

        // Edge Polarity Selection based on ELSB:ELSA bits of the CnSC register
        switch (Icu_Channels_Config_ptr[i].Icu_Activation)
        {
        case ICU_RISING_EDGE:
            // ELSB:ELSA = 0:1 ==> Rising Edge
            *ftm_cnsc &= ~(1 << 3);
            *ftm_cnsc |= (1 << 2);
            break;
        case ICU_FALLING_EDGE:
            // ELSB:ELSA = 1:0 ==> Falling Edge
            *ftm_cnsc |= (1 << 3);
            *ftm_cnsc &= ~(1 << 2);
            break;
        case ICU_BOTH_EDGES:
            // ELSB:ELSA = 1:1 ==> Both Edges
            *ftm_cnsc |= (3 << 2);
            break;
        default:
            break;
        }
        /*
         * [SWS_Icu_00061]: The function Icu_Init shall disable all notifications :
         * disable interruptions by clearing the CHIE bit of the correspondent Channel CnSC Reg
         */
        // fix: All interrupts must be disabled not only those enabled in configuration !
        *ftm_cnsc &= ~CnSC_CHIE_MASK;
        /*
         * [SWS_Icu_00121] ⌈The function Icu_Init shall disable the wakeup-capability of all channels.
         * if the channel is wake-up capable then call the Ecu state Manager disable it.
         */
        if (1 == Icu_Channels_Config_ptr[i].IcuWakeup.IcuWakeupCapability)
        {
            EcuM_ClearWakeupEvent(Icu_Channels_Config_ptr[i].IcuWakeup.IcuChannelWakeupInfo);
        }
        // Set the filter value for the corresponding channel (only for Channles 0 to 3 in each FTM instance)
        if((1 == Icu_Channels_Config_ptr[i].Icu_FilterEnable) && (CnId <= 3)){
            Icu_ChannelFilterValueType filter_value = Icu_Channels_Config_ptr[i].Icu_ChannelFilterValue;
            *ftm_fltr &= ~(0x0F << (CnId * 4)); // clear the existing filer value
            *ftm_fltr |= (filter_value << (CnId * 4)); // then Set the new filter value
        }
        /*
         * [SWS_Icu_00040] ⌈The function Icu_Init shall set all used ICU channels to status ICU_IDLE.
         * So that mean at init no activation edge has been detected yet
         */
        Icu_Channels_Config_ptr[i].Icu_InputState = ICU_IDLE;

        /*[SWS_Icu_00060] ⌈The function Icu_Init shall set the module mode to ICU_MODE_NORMAL.
         * Normal operation, all used interrupts are enabled according to the notification requests.
         */
        Icu_Channels_Config_ptr[i].Icu_Mode = ICU_MODE_NORMAL;
    }
    // Start the FTM counter
    Ftm_Configured_Mask = 0;
    for (uint8 i = 0; i < Icu_NumberOf_Channels; i++)
    {
        Icu_FTM_ID FtmId = get_instance_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);
        volatile uint32 *ftm_sc = NULL_PTR;

        // check if the PCC of the FTM instance is alerady initialized
        if ((Ftm_Configured_Mask) & (1 << FtmId))
        {
            continue;
        }

        switch (FtmId)
        {
        case FTM_0:
            ftm_sc = (volatile uint32 *)(FTM_0_SC);
            break;
        case FTM_1:
            ftm_sc = (volatile uint32 *)(FTM_1_SC);
            break;
        case FTM_2:
            ftm_sc = (volatile uint32 *)(FTM_2_SC);
            break;
        case FTM_3:
            ftm_sc = (volatile uint32 *)(FTM_3_SC);
            break;
        default:
            // Do Nothing
            break;
        }
        // // Select system clock as timer source (CLKS = 01)
        *ftm_sc |= (1 << 3);
        Ftm_Configured_Mask |= (1 << FtmId);
    }
    Icu_Status = ICU_INITIALIZED;
}

#if(STD_ON == ICU_DEINIT_API)
void Icu_DeInit (void){

    #if(STD_ON == ICU_DEV_ERROR_DETECT)
        if(ICU_NOT_INITIALIZED == Icu_Status){
            Det_ReportError(ICU_MODULE_ID, ICU_MODULE_INSTANCE_ID, ICU_DEINIT_SID, ICU_E_UNINIT);
            return;
        }
    #endif

    if(ICU_INITIALIZED == Icu_Status){
        /* [SWS_Icu_00036]: The function Icu_DeInit shall set the state of the peripherals
         * used by configuration as the same after power on reset.
         */
        Ftm_Configured_Mask = 0;
        for (uint8 i = 0; i < Icu_NumberOf_Channels; i++)
        {
            Icu_FTM_ID FtmId = get_instance_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);

            volatile uint32 *ftm_mode = NULL_PTR;
            volatile uint32 *ftm_combine = NULL_PTR;
            volatile uint32 *ftm_sc = NULL_PTR;
            volatile uint32 *ftm_cnt = NULL_PTR;
            volatile uint32 *ftm_mod = NULL_PTR;
            volatile uint32 *ftm_cint = NULL_PTR;

            // check if the PCC of the FTM instance is alerady initialized
            if ((Ftm_Configured_Mask) & (1 << FtmId))
            {
                continue;
            }

            switch (FtmId)
            {
            case FTM_0:
                ftm_mode = (volatile uint32 *)(FTM_0_MODE);
                ftm_combine = (volatile uint32 *)(FTM_0_COMBINE);
                ftm_sc = (volatile uint32 *)(FTM_0_SC);
                ftm_cnt = (volatile uint32 *)(FTM_0_CNT);
                ftm_mod = (volatile uint32 *)(FTM_0_MOD);
                ftm_cint = (volatile uint32 *)(FTM_0_CNTIN);
                break;
            case FTM_1:
                ftm_mode = (volatile uint32 *)(FTM_1_MODE);
                ftm_combine = (volatile uint32 *)(FTM_1_COMBINE);
                ftm_sc = (volatile uint32 *)(FTM_1_SC);
                ftm_cnt = (volatile uint32 *)(FTM_1_CNT);
                ftm_mod = (volatile uint32 *)(FTM_1_MOD);
                ftm_cint = (volatile uint32 *)(FTM_1_CNTIN);
                break;
            case FTM_2:
                ftm_mode = (volatile uint32 *)(FTM_2_MODE);
                ftm_combine = (volatile uint32 *)(FTM_2_COMBINE);
                ftm_sc = (volatile uint32 *)(FTM_2_SC);
                ftm_cnt = (volatile uint32 *)(FTM_2_CNT);
                ftm_mod = (volatile uint32 *)(FTM_2_MOD);
                ftm_cint = (volatile uint32 *)(FTM_2_CNTIN);
                break;
            case FTM_3:
                ftm_mode = (volatile uint32 *)(FTM_3_MODE);
                ftm_combine = (volatile uint32 *)(FTM_3_COMBINE);
                ftm_sc = (volatile uint32 *)(FTM_3_SC);
                ftm_cnt = (volatile uint32 *)(FTM_3_CNT);
                ftm_mod = (volatile uint32 *)(FTM_3_MOD);
                ftm_cint = (volatile uint32 *)(FTM_3_CNTIN);
                break;
            default:
                // Do Nothing
                break;
            }

            // Disable write protection of the FTM instance
            *ftm_mode |= MODE_WPDIS_MASK;

            // Reset the state of the SC Register as after Reset 
            // Note: Start with the SC Register to Disable the FTM CLKS[1:0]
            *ftm_sc &= ~SC_RESET_MASK;

            // Reset the FTM Counter Register
            *ftm_cnt &= ~CNT_RESET_MASK;
            // Reset the state of the COMBINE Register as after Reset
            *ftm_combine &= ~COMBINE_RESET_MASK;

            // Reset the state of the MOD Register as after Reset
            *ftm_mod &= ~MOD_RESET_MASK;

            // Reset the state of the CNT Register as after Reset
            *ftm_cint &= ~CNTIN_RESET_MASK;

            Ftm_Configured_Mask |= (1 << FtmId);
        }

        /*[SWS_Icu_00037]: The function Icu_DeInit shall disable all used interrupts and notifications.*/
        for (uint8 i = 0; i < Icu_NumberOf_Channels; i++)
        {
            Icu_FTM_ID FtmId = get_instance_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);
            Icu_ChannelType CnId = get_Channel_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);

            volatile uint32 *ftm_cnsc = NULL_PTR;

            switch (FtmId)
            {
            case FTM_0:
                ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_0_BASSE_ADDRESS + CnSC_OFFSET(CnId)); // the cast to unit8* is to ensure byte-level ptr arithmitic
                break;
            case FTM_1:
                ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_1_BASSE_ADDRESS + CnSC_OFFSET(CnId));
                break;
            case FTM_2:
                ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_2_BASSE_ADDRESS + CnSC_OFFSET(CnId));
                break;
            case FTM_3:
                ftm_cnsc = (volatile uint32 *)((uint8 *)FTM_3_BASSE_ADDRESS + CnSC_OFFSET(CnId));
                break;
            default:
                // Do Nothing
                break;
            }
            
            *ftm_cnsc &= ~CnSC_RESET_MASK;
        }
        // Reset the MODE register after reseting all other register because of the Write Protection Property
        Ftm_Configured_Mask = 0;
        for (uint8 i = 0; i < Icu_NumberOf_Channels; i++)
        {
            Icu_FTM_ID FtmId = get_instance_id(Icu_Channels_Config_ptr[i].Icu_ChannelId);
            volatile uint32 *ftm_mode = NULL_PTR;
            volatile uint32 *pcc_address = NULL_PTR;

            // check if the PCC of the FTM instance is alerady initialized
            if ((Ftm_Configured_Mask) & (1 << FtmId))
            {
                continue;
            }

            switch (FtmId)
            {
            case FTM_0:
                pcc_address = (volatile uint32 *)PCC_FTM_0;
                ftm_mode = (volatile uint32 *)(FTM_0_MODE);
                break;
            case FTM_1:
                pcc_address = (volatile uint32 *)PCC_FTM_1;
                ftm_mode = (volatile uint32 *)(FTM_1_MODE);
                break;
            case FTM_2:
                pcc_address = (volatile uint32 *)PCC_FTM_2;
                ftm_mode = (volatile uint32 *)(FTM_2_MODE);
                break;
            case FTM_3:
                pcc_address = (volatile uint32 *)PCC_FTM_3;
                ftm_mode = (volatile uint32 *)(FTM_3_MODE);
                break;
            default:
                // Do Nothing
                break;
            }

            // Reset the state of the MODE Register as after Reset
            *ftm_mode &= ~MODE_RESET_MASK;

            // Disable FTM instance Clock
            *pcc_address &= ~PCC_CGC_MASK;

            Ftm_Configured_Mask |= (1 << FtmId);
        }

        // Clear global Configuration
        Icu_Channels_Config_ptr = NULL_PTR;
        Icu_NumberOf_Channels = 0;
        Icu_Status = ICU_NOT_INITIALIZED;
    }
}
#endif