#ifndef ICU_H_
#define ICU_H_

/****************************************************************************************************/
/*                                      Includes                                                    */
/****************************************************************************************************/
#include "Icu_Types.h"
#include "Compiler.h"
#include "Common_Macros.h"

/****************************************************************************************************/
/*                   MACROS: used in error detection & get version Api                              */
/****************************************************************************************************/
#define ICU_MODULE_ID                              (122U)
#define ICU_MODULE_INSTANCE_ID                     (0U)
#define ICU_MODULE_VENDOR_ID                       (0xD0) /* My own vendor id (company dependent): highest vid is 0xC7(Real-Time Innovations)*/

/* Module version 1.0.0 */
#define ICU_MODULE_MAJOR_VERSION                   (1U)
#define ICU_MODULE_MINOR_VERSION                   (0U)
#define ICU_MODULE_PATCH_VERSION                   (0U)

#define ICU_NOT_INITIALIZED                        (0U)
#define ICU_INITIALIZED                            (1U)

/*********************************************************************************************************
 *                                              API Service Id Macros                                    *
 *********************************************************************************************************/

#define ICU_INIT_SID                                (uint8)0x00
#define ICU_DEINIT_SID                              (uint8)0x01

#define ICU_SET_MODE_SID                            (uint8)0x02

#define ICU_DISABLE_WAKEUP_SID                      (uint8)0x03
#define ICU_ENABLE_WAKEUP_SID                       (uint8)0x04

#define ICU_SET_ACTIVATION_CONDITION_SID            (uint8)0x05

#define ICU_DISABLE_NOTIFICATION_SID                (uint8)0x06
#define ICU_ENABLE_NOTIFICATION_SID                 (uint8)0x07

#define ICU_GET_INPUT_STATE_SID                     (uint8)0x08

#define ICU_START_TIMESTAMP_SID                     (uint8)0x09
#define ICU_STOPT_IMESTAMP_SID                      (uint8)0x0A
#define ICU_GET_TIMESTAMP_INDEX_SID                 (uint8)0x0B

#define ICU_RESET_EDGE_COUNT_SID                    (uint8)0x0C
#define ICU_ENABLE_EDGE_COUNT_SID                   (uint8)0x0D
#define ICU_DISABLE_EDGE_COUNT_SID                  (uint8)0x0E

#define ICU_GET_EDGE_NUMBERS_SID                    (uint8)0x0F
#define ICU_GET_TIME_ELAPSED_SID                    (uint8)0x10
#define ICU_GET_DUTY_CYCLE_VALUES_SID               (uint8)0x11
#define ICU_GET_VERSION_INFO_SID                    (uint8)0x12

#define ICU_START_SIGNAL_MEASUREMENT_SID            (uint8)0x13
#define ICU_STOP_SIGNAL_MEASUREMENT_SID             (uint8)0x14

#define ICU_CHECK_WAKEUP_SID                        (uint8)0x15
#define ICU_ENABLE_EDGE_DETECTION_SID               (uint8)0x16
#define ICU_DISABLE_EDGE_DETECTION_SID              (uint8)0x17

#define ICU_DISABLE_NOTIFICATION_ASYNC_SID          (uint8)0x18
#define ICU_ENABLE_NOTIFICATION_ASYNC_SID           (uint8)0x19

/****************************************************************************************************/
/*                                      IcuGeneral                                                  */
/****************************************************************************************************/

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00232] 
 * Parameter Name: IcuDevErrorDetect
 * Parent Container: IcuGeneral
 * Description: Switches the development error detection and notification on or off:
 *              - true: detection and notification is enabled.
 *              - false: detection and notification is disabled.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_DEV_ERROR_DETECT                        (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00233] 
 * Parameter Name: IcuReportWakeupSource
 * Parent Container: IcuGeneral
 * Description: Switch for enabling Wakeup source reporting:
 *              - true: Report Wakeup source.
 *              - false: Do not report Wakeup source.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_REPORT_WAKEUP_SOURCE                    (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00234] 
 * Parameter Name: IcuDeInitApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_DeInit() from the code:
 *              - true: Icu_DeInit() can be used.
 *              - false: Icu_DeInit() can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_DEINIT_API                              (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00235] 
 * Parameter Name: IcuDisableWakeupApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_DisableWakeup() from the code:
 *              - true: Icu_DisableWakeup() can be used.
 *              - false: Icu_DisableWakeup() can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_DISABLE_WAKEUP_API                      (STD_OFF)


/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00124] 
 * Parameter Name: IcuEdgeCountApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes all services related to the edge counting functionality as listed below,
 *              from the code: Icu_ResetEdgeCount(), Icu_EnableEdgeCount(), Icu_DisableEdgeCount(),
 *              Icu_GetEdgeNumbers().
 *              - true: The services listed above can be used.
 *              - false: The services listed above can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_EDGE_COUNT_API                          (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00356] 
 * Parameter Name: IcuEdgeDetectApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the services related to the edge detection functionality, from 
 *              the code: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection().
 *              - true: The services can be used.
 *              - false: The services can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_EDGE_DETECT_API                         (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00236]
 * Parameter Name: IcuEnableWakeupApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_EnableWakeup() from the code. 
 *              - true: Icu_EnableWakeup() service can be used.
 *              - false: Icu_EnableWakeup() service can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_ENABLE_WAKEUP_API                       (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00237]
 * Parameter Name: IcuGetDutyCycleValuesApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_GetDutyCycleValues() from the code. 
 *              - true: Icu_GetDutyCycleValues() service can be used.
 *              - false: Icu_GetDutyCycleValues() service can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_GET_DUTY_CYCLE_VALUES_API               (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00238]
 * Parameter Name: IcuGetInputStateApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_GetInputState() from the code. 
 *              - true: Icu_GetInputState() service can be used.
 *              - false: Icu_GetInputState() service can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_GET_INPUT_STATE_API                     (STD_OFF)


/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00239]
 * Parameter Name: IcuGetTimeElapsedApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_GetTimeElapsed() from the code. 
 *              - true: Icu_GetTimeElapsed() service can be used.
 *              - false: Icu_GetTimeElapsed() service can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_GET_TIME_ELAPSED_API                    (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00241]
 * Parameter Name: IcuSetModeApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_SetMode() from the code. 
 *              - true: Icu_SetMode() service can be used.
 *              - false: Icu_SetMode() service can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_SET_MODE_API                            (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00242]
 * Parameter Name: IcuSignalMeasurementApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the services Icu_StartSignalMeasurement() and 
 *              Icu_StopSignalMeasurement() from the code.  
 *              - true: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() services can be used.
 *              - false: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() service can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_SIGNAL_MEASUREMENT_API                  (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00123]
 * Parameter Name: IcuTimestampApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes all services related to the timestamping functionality as listed below,
 *              from the code:  Icu_StartTimestamp(), Icu_StopTimestamp(), Icu_GetTimestampIndex().
 *              - true: The services listed above can be used.
 *              - false: The services listed above can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_TIMESTAMP_API                           (STD_OFF)

/****************************************************************************************************
 * SWS Item: [ECUC_Icu_00355]
 * Parameter Name: IcuWakeupFunctionalityApi
 * Parent Container: IcuOptionalApis
 * Description: Adds / removes the service Icu_CheckWakeup() from the code. 
 *              - true: Icu_CheckWakeup() service can be used.
 *              - false: Icu_CheckWakeup() service can not be used.
 * Multiplicity: 1
 * Default value: false
 * scope: local
 ****************************************************************************************************/
#define ICU_WAKEUP_FUNCTIONALITY_API                (STD_OFF)


/****************************************************************************************************/
/*                                 Function definitions                                             */
/****************************************************************************************************/

/****************************************************************************************************
 * Service Name: Icu_Init
 * Sws_Index : 8.3.1 [SWS_Icu_00191]
 * Service ID[hex]:0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr - Pointer to a selected configuration structure
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function initializes the driver.
 ****************************************************************************************************/
void Icu_Init (const Icu_ConfigType* ConfigPtr);

/****************************************************************************************************
 * Service Name: Icu_DeInit
 * Sws_Index : 8.3.2 [SWS_Icu_00193]
 * Service ID[hex]:0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function de-initializes the ICU module
 ****************************************************************************************************/
void Icu_DeInit (void);

/****************************************************************************************************
 * Service Name: Icu_SetMode
 * Sws_Index : 8.3.3 [SWS_Icu_00194]
 * Service ID[hex]:0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Mode:
*                   - ICU_MODE_NORMAL: Normal operation, all used interrupts are enabled 
*                     according to the notification requests
*                   - ICU_MODE_SLEEP: Reduced power mode. In sleep mode only those notifications
*                     are available which are configured as wakeup capable.                      
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function sets the ICU mode. 
 ****************************************************************************************************/
void Icu_SetMode (Icu_ModeType Mode);

/****************************************************************************************************
 * Service Name: Icu_DisableWakeup
 * Sws_Index : 8.3.4 [SWS_Icu_00195]
 * Service ID[hex]:0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel        
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function disables the wakeup capability of a single ICU channel
 ****************************************************************************************************/
void Icu_DisableWakeup (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_EnableWakeup
 * Sws_Index : 8.3.5 [SWS_Icu_00196]
 * Service ID[hex]:0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel        
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function (re-)enables the wakeup capability of the given ICU channel.
 ****************************************************************************************************/
void Icu_EnableWakeup (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_CheckWakeup
 * Sws_Index : 8.3.6 [SWS_Icu_00358]
 * Service ID[hex]:0x15
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): WakeupSource - Informatin on wakeup source to be checked. The associated ICU 
                                    channel can be determined from configuration data.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Checks if a wakeup capable ICU channel is the source for a wakeup event and calls 
                the ECU state manager service EcuM_SetWakeupEvent in case of a valid ICU 
                channel wakeup event. 
 ****************************************************************************************************/
void Icu_CheckWakeup (EcuM_WakeupSourceType WakeupSource);

/****************************************************************************************************
 * Service Name: Icu_SetActivationCondition
 * Sws_Index : 8.3.7 [SWS_Icu_00197]
 * Service ID[hex]:0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 *                  Activation - Type of activation (if supported by hardware).
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function sets the activation-edge for the given channel.
 ****************************************************************************************************/
void Icu_SetActivationCondition (Icu_ChannelType Channel, Icu_ActivationType Activation);

/****************************************************************************************************
 * Service Name: Icu_DisableNotification
 * Sws_Index : 8.3.8 [SWS_Icu_00198]
 * Service ID[hex]:0x06
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function disables the notification of a channel.
 ****************************************************************************************************/
void Icu_DisableNotification (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_EnableNotification
 * Sws_Index : 8.3.9 [SWS_Icu_00199]
 * Service ID[hex]:0x07
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function enables the notification on the given channel.
 ****************************************************************************************************/
void Icu_EnableNotification (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_GetInputState
 * Sws_Index : 8.3.10 [SWS_Icu_00200]
 * Service ID[hex]:0x08
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Icu_InputStateType (ICU_ACTIVE or ICU_IDLE)
 * Description: This function returns the status of the ICU input.
 ****************************************************************************************************/
Icu_InputStateType Icu_GetInputState (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_StartTimestamp
 * Sws_Index : 8.3.11 [SWS_Icu_00201]
 * Service ID[hex]:0x09
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 *                  BufferSize - Size of the external buffer (number of entries).
 *                  NotifyInterval - Notification interval (number of events). This parameter can not be 
 *                                   checked in a reasonable way. 
 * Parameters (inout): None
 * Parameters (out): BufferPtr - Pointer to the buffer-array where the timestamp values shall be placed.
 * Return value: None
 * Description: This function starts the capturing of timer values on the edges.
 ****************************************************************************************************/
void Icu_StartTimestamp (Icu_ChannelType Channel, Icu_ValueType* BufferPtr, uint16 BufferSize, uint16 NotifyInterval);

/****************************************************************************************************
 * Service Name: Icu_StopTimestamp
 * Sws_Index : 8.3.12 [SWS_Icu_00202]
 * Service ID[hex]:0x0a
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function stops the timestamp measurement of the given channel. 
 ****************************************************************************************************/
void Icu_StopTimestamp (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_GetTimestampIndex
 * Sws_Index : 8.3.13 [SWS_Icu_00203]
 * Service ID[hex]:0x0b
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): Icu_IndexType - Abstract return type to cover different microcontrollers. 
 * Return value: None
 * Description: This function reads the timestamp index of the given channel.
 ****************************************************************************************************/
Icu_IndexType Icu_GetTimestampIndex (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_ResetEdgeCount
 * Sws_Index : 8.3.14 [SWS_Icu_00204]
 * Service ID[hex]:0x0c
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function reads the timestamp index of the given channel.
 ****************************************************************************************************/
void Icu_ResetEdgeCount (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_EnableEdgeCount
 * Sws_Index : 8.3.15 [SWS_Icu_00205]
 * Service ID[hex]:0x0d
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function enables the counting of edges of the given channel.
 ****************************************************************************************************/
void Icu_EnableEdgeCount (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_EnableEdgeDetection
 * Sws_Index : 8.3.16 [SWS_Icu_00364]
 * Service ID[hex]:0x16
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function enables / re-enables the detection of edges of the given channel.
 ****************************************************************************************************/
void Icu_EnableEdgeDetection (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_DisableEdgeDetection
 * Sws_Index : 8.3.17 [SWS_Icu_00377]
 * Service ID[hex]:0x17
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function disables the detection of edges of the given channel.
 ****************************************************************************************************/
void Icu_DisableEdgeDetection (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_DisableEdgeCount
 * Sws_Index : 8.3.18 [SWS_Icu_00206]
 * Service ID[hex]:0x0e
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function disables the counting of edges of the given channel. 
 ****************************************************************************************************/
void Icu_DisableEdgeCount (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_EnableEdgeDetection
 * Sws_Index : 8.3.19 [SWS_Icu_00207]
 * Service ID[hex]:0x0f
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function reads the number of counted edges.
 ****************************************************************************************************/
Icu_EdgeNumberType Icu_GetEdgeNumbers (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_StartSignalMeasurement
 * Sws_Index : 8.3.20 [SWS_Icu_00208]
 * Service ID[hex]:0x13
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function starts the measurement of signals.
 ****************************************************************************************************/
void Icu_StartSignalMeasurement (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_StopSignalMeasurement
 * Sws_Index : 8.3.21 [SWS_Icu_00209]
 * Service ID[hex]:0x14
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function stops the measurement of signals of the given channel.
 ****************************************************************************************************/
void Icu_StopSignalMeasurement (Icu_ChannelType Channel); 

/****************************************************************************************************
 * Service Name: Icu_GetTimeElapsed
 * Sws_Index : 8.3.22 [SWS_Icu_00210]
 * Service ID[hex]:0x10
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Icu_ValueType - Width of the buffer for timestamp ticks and measured elapsed timeticks
 * Description: This function reads the elapsed Signal Low Time for the given channel.
 ****************************************************************************************************/
Icu_ValueType Icu_GetTimeElapsed (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_GetDutyCycleValues
 * Sws_Index : 8.3.23 [SWS_Icu_00211]
 * Service ID[hex]:0x11
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): DutyCycleValues - Pointer to a buffer where the results (high time and period time) 
                                        shall be placed. 
 * Return value: None
 * Description: This function reads the coherent active time and period time for the given ICU Channel. 
 ****************************************************************************************************/
void Icu_GetDutyCycleValues (Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues);

/****************************************************************************************************
 * Service Name: Icu_GetVersionInfo
 * Sws_Index : 8.3.24 [SWS_Icu_00212]
 * Service ID[hex]:0x12
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): versioninfo - Pointer to where to store the version information of this module. 
 * Return value: None
 * Description: This function returns the version information of this module.
 ****************************************************************************************************/
void Icu_GetVersionInfo (Std_VersionInfoType* versioninfo);

/****************************************************************************************************
 * Service Name: Icu_DisableNotificationAsync
 * Sws_Index : 8.3.25 [SWS_Icu_91002]
 * Service ID[hex]:0x18
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None 
 * Return value: None
 * Description: This function disables the notification of a channel.
 ****************************************************************************************************/
void Icu_DisableNotificationAsync (Icu_ChannelType Channel);

/****************************************************************************************************
 * Service Name: Icu_EnableNotificationAsync
 * Sws_Index : 8.3.26 [SWS_Icu_91003]
 * Service ID[hex]:0x19
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the ICU channel.
 * Parameters (inout): None
 * Parameters (out): None 
 * Return value: None
 * Description: This function enables the notification on the given channel.
 ****************************************************************************************************/
void Icu_EnableNotificationAsync (Icu_ChannelType Channel);

#endif /* ICU_H_*/