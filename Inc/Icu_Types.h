#ifndef ICU_TYPES_H
#define ICU_TYPES_H

/****************************************************************************************************/
/*                                      Includes                                                    */
/****************************************************************************************************/
#include "Std_Types.h"
#include "EcuM.h"

/****************************************************************************************************/
/*                                  [SWS_Icu_00382] Development Errors                              */
/****************************************************************************************************/

/* API IS called with invalid pointer. */
#define ICU_E_PARAM_POINTER             0x0A

/* API service used with an invalid channel identifier or channel 
was not configured for the functionality of the calling API. */
#define ICU_E_PARAM_CHANNEL             0x0B

/* API service used with an invalid or not feasible activation. */
#define ICU_E_PARAM_ACTIVATION          0x0C

/* Init function failed.*/
#define ICU_E_INIT_FAILED               0x0D

/* API service used with an invalid buffer size. */
#define ICU_E_PARAM_BUFFER_SIZE         0x0E

/* API service Icu_SetMode used with an invalid mode. */
#define ICU_E_PARAM_MODE                0x0F

/* API service used without module initialization. */
#define ICU_E_UNINIT                    0x14

/* API service Icu_SetMode is called while a running operation.  */
#define ICU_E_BUSY_OPERATION            0x16

/* API Icu_Init service is called and when the ICU driver and the 
Hardware are already initialized. */
#define ICU_E_ALREADY_INITIALIZED       0x17

/* API Icu_StartTimeStamp is called and the parameter Notify
 Interval is invalid (e.g."0", NotifyInterval < 1). */
#define ICU_E_PARAM_NOTIFY_INTERVAL     0x18

/* API Icu_GetVersionInfo is called and the parameter 
versioninfo is is invalid ( e.g. NULL ). */
#define ICU_E_PARAM_VINFO               0x19

/****************************************************************************************************/
/*                                  [SWS_Icu_91004] Runtime Errors                                  */
/****************************************************************************************************/

/* API service Icu_StopTimestamp called on a channel which was 
not started or already stopped. */
#define ICU_E_NOT_STARTED             0x15


/****************************************************************************************************/
/*                                      Types Definitions                                           */
/****************************************************************************************************/

/*
 * Index : 8.2.1 [SWS_Icu_00277]
 * Description : Allow enabling / disabling of all interrupts which are not required for the ECU wakeup.
 */
enum Icu_ModeType {
    ICU_MODE_NORMAL,
    ICU_MODE_SLEEP
};
typedef enum Icu_ModeType Icu_ModeType;

/*
 * Index : 8.2.2 [SWS_Icu_00278]
 * Description : Numeric identifier of an ICU channel.
 */
typedef uint16 Icu_ChannelType;
// FTM0
#define FTM_0_CHANNEL_0             (Icu_ChannelType)0x00
#define FTM_0_CHANNEL_1             (Icu_ChannelType)0x01
#define FTM_0_CHANNEL_2             (Icu_ChannelType)0x02
#define FTM_0_CHANNEL_3             (Icu_ChannelType)0x03
#define FTM_0_CHANNEL_4             (Icu_ChannelType)0x04
#define FTM_0_CHANNEL_5             (Icu_ChannelType)0x05
#define FTM_0_CHANNEL_6             (Icu_ChannelType)0x06
#define FTM_0_CHANNEL_7             (Icu_ChannelType)0x07

// FTM1
#define FTM_1_CHANNEL_0             (Icu_ChannelType)0x08
#define FTM_1_CHANNEL_1             (Icu_ChannelType)0x09
#define FTM_1_CHANNEL_2             (Icu_ChannelType)0x0A
#define FTM_1_CHANNEL_3             (Icu_ChannelType)0x0B
#define FTM_1_CHANNEL_4             (Icu_ChannelType)0x0C
#define FTM_1_CHANNEL_5             (Icu_ChannelType)0x0D
#define FTM_1_CHANNEL_6             (Icu_ChannelType)0x0E
#define FTM_1_CHANNEL_7             (Icu_ChannelType)0x0F

// FTM2
#define FTM_2_CHANNEL_0             (Icu_ChannelType)0x10
#define FTM_2_CHANNEL_1             (Icu_ChannelType)0x11
#define FTM_2_CHANNEL_2             (Icu_ChannelType)0x12
#define FTM_2_CHANNEL_3             (Icu_ChannelType)0x13
#define FTM_2_CHANNEL_4             (Icu_ChannelType)0x14
#define FTM_2_CHANNEL_5             (Icu_ChannelType)0x15
#define FTM_2_CHANNEL_6             (Icu_ChannelType)0x16
#define FTM_2_CHANNEL_7             (Icu_ChannelType)0x17

// FTM3
#define FTM_3_CHANNEL_0             (Icu_ChannelType)0x18
#define FTM_3_CHANNEL_1             (Icu_ChannelType)0x19
#define FTM_3_CHANNEL_2             (Icu_ChannelType)0x1A
#define FTM_3_CHANNEL_3             (Icu_ChannelType)0x1B
#define FTM_3_CHANNEL_4             (Icu_ChannelType)0x1C
#define FTM_3_CHANNEL_5             (Icu_ChannelType)0x1D
#define FTM_3_CHANNEL_6             (Icu_ChannelType)0x1E
#define FTM_3_CHANNEL_7             (Icu_ChannelType)0x1F

typedef uint8 Icu_FTM_ID;
#define FTM_0                       (Icu_FTM_ID)0x00
#define FTM_1                       (Icu_FTM_ID)0x01
#define FTM_2                       (Icu_FTM_ID)0x02
#define FTM_3                       (Icu_FTM_ID)0x03

#define CHANNELS_PER_INSTANCE       (uint8)0x08
/*
 * Index : 10.2.9 [ECUC_Icu_00220] 
 * Description : This parameter contains the number of Channels configured.
 */
#define ICU_MAX_CHANNEL             (Icu_ChannelType)32U

/*
 * Index : 8.2.3 [SWS_Icu_00279]
 * Description : Input state of an ICU channel.
 */
enum Icu_InputStateType{
    ICU_ACTIVE,
    ICU_IDLE
};
typedef enum Icu_InputStateType Icu_InputStateType;

/*
 * Type that absrtact the prescaler value (divide-by 1, 2, 4, 8, 16, 32, 64, or 128)
*/
typedef uint8 Icu_ClockPrescalerType;
#define ICU_CLK_PRESCALER_0                 (Icu_ClockPrescalerType)1U
#define ICU_CLK_PRESCALER_1                 (Icu_ClockPrescalerType)2U
#define ICU_CLK_PRESCALER_2                 (Icu_ClockPrescalerType)4U
#define ICU_CLK_PRESCALER_3                 (Icu_ClockPrescalerType)8U
#define ICU_CLK_PRESCALER_4                 (Icu_ClockPrescalerType)16U
#define ICU_CLK_PRESCALER_5                 (Icu_ClockPrescalerType)32U
#define ICU_CLK_PRESCALER_6                 (Icu_ClockPrescalerType)64U
#define ICU_CLK_PRESCALER_7                 (Icu_ClockPrescalerType)128U

/*
 * Index : 8.2.4 [SWS_Icu_00280]
 * Description : This type contains initialization data.
 */

struct Icu_ConfigType {
    uint8 Icu_NumberOfChannels;
    Icu_ChannelConfigType* Icu_ChannelConfig;
};
typedef struct Icu_ConfigType Icu_ConfigType;

struct Icu_ChannelConfigType{
    Icu_ChannelType Icu_ChannelId;
    Icu_MeasurementModeType Icu_MeasurementMode;
    Icu_ActivationType Icu_Activation;
    Icu_ClockPrescalerType Icu_ClockPrescaler;
    IcuSignalEdgeDetectionType IcuSignalEdgeDetection;
    IcuSignalMeasurementType IcuSignalMeasurement;
    IcuTimestampMeasurementType IcuTimestampMeasurement;
    Icu_InputStateType Icu_InputState;
    Icu_ModeType Icu_Mode;
    IcuWakeupType IcuWakeup;
    boolean Icu_FilterEnable;
    boolean Icu_InterruptEnable;
};

typedef struct Icu_ChannelConfigType Icu_ChannelConfigType;

/*
 * Index : 10.2.5 [ECUC_Icu_00021]
 * Description : This container contains the configuration (parameters) in case the measurement 
 *               mode is "IcuSignalEdgeDetection".
 */
struct IcuSignalEdgeDetectionType{
    //Pointer to a function that gets called when an edge is detected.
    void (*IcuSignalNotification)(void);
};
typedef struct IcuSignalEdgeDetectionType IcuSignalEdgeDetectionType;

/*
 * Index : 10.2.6 [ECUC_Icu_00226]
 * Description : This container contains the configuration (parameters) in case the measurement 
 *               mode is "IcuSignalMeasurement" 
 */
struct IcuSignalMeasurementType{
    Icu_SignalMeasurementPropertyType IcuSignalMeasurementProperty;
};
typedef struct IcuSignalMeasurementType IcuSignalMeasurementType;

/*
 * Index : 10.2.7 [ECUC_Icu_00228]
 * Description : This container contains the configuration (parameters) in case the measurement 
 *               mode is "IcuTimestamp"  
 */
struct IcuTimestampMeasurementType{
    // Notification function if the number of requested timestamps (Notification interval > 0) are acquired.
    void (*IcuTimestampNotification)(void);
    Icu_TimestampBufferType IcuTimestampMeasurementProperty;
};
typedef struct IcuTimestampMeasurementType IcuTimestampMeasurementType;
boolean IcuWakeupCapability;

/*
 * Index : 10.2.8 [ECUC_Icu_00126]
 * Description : This container contains the configuration (parameters) needed to configure a 
 *               wakeup capable channel
 */
struct IcuWakeupType{
    EcuM_WakeupSourceType IcuChannelWakeupInfo;
    boolean IcuWakeupCapability;
};
typedef struct IcuWakeupType IcuWakeupType;

/*
 * Index : 8.2.5 [SWS_Icu_00289]
 * Description : Definition of the type of activation of an ICU channel.
 */
enum Icu_ActivationType {
    ICU_RISING_EDGE,
    ICU_FALLING_EDGE,
    ICU_BOTH_EDGES
};
typedef enum Icu_ActivationType Icu_ActivationType;

/*
 * Index : 8.2.6 [SWS_Icu_00290]
 * Description : Width of the buffer for timestamp ticks and measured elapsed timeticks.
 */
typedef uint32 Icu_ValueType;

/*
 * Index : 8.2.7 [SWS_Icu_00291]
 * Description : Type which shall contain the values, needed for calculating duty cycles.
 */
struct Icu_DutyCycleType {
    Icu_ValueType ActiveTime;
    Icu_ValueType PeriodTime;
};
typedef struct Icu_DutyCycleType Icu_DutyCycleType;

/*
 * Index : 8.2.8 [SWS_Icu_00292]
 * Description : Type, to abstract the return value of the service Icu_GetTimestampIndex().
 */
typedef uint8 Icu_IndexType;

/*
 * Index : 8.2.9 [SWS_Icu_00293]
 * Description : Type, to abstract the return value of the service Icu_GetEdgeNumbers().
 */
typedef uint8 Icu_EdgeNumberType;


/*
 * Index : 8.2.10 [SWS_Icu_00294]
 * Description : Definition of the measurement mode type.
 */
enum Icu_MeasurementModeType{
    ICU_MODE_SIGNAL_EDGE_DETECT,
    ICU_MODE_SIGNAL_MEASUREMENT,
    ICU_MODE_TIMESTAMP,
    ICU_MODE_EDGE_COUNTER
};
typedef enum Icu_MeasurementModeType Icu_MeasurementModeType;

/*
 * Index : 8.2.11 [SWS_Icu_00295]
 * Description : Definition of the measurement property type.
 */
enum Icu_SignalMeasurementPropertyType{
    ICU_LOW_TIME ,
    ICU_HIGH_TIME ,
    ICU_PERIOD_TIME,
    ICU_DUTY_CYCLE 
};
typedef enum Icu_SignalMeasurementPropertyType Icu_SignalMeasurementPropertyType;

/*
 * Index : 8.2.12 [SWS_Icu_00296]
 * Description : Definition of the timestamp measurement property type.
 */
enum Icu_TimestampBufferType {
    ICU_LINEAR_BUFFER,
    ICU_CIRCULAR_BUFFER 
};
typedef enum Icu_TimestampBufferType Icu_TimestampBufferType;

/*
 * Index : 8.3.19 [SWS_Icu_00207]
 * Description : type that abstract the return type of the Icu_GetEdgeNumbers() service .
 */
typedef uint32 Icu_EdgeNumberType;
#endif /* ICU_TYPES_H */
