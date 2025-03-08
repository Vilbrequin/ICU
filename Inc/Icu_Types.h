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
typedef uint8 Icu_ChannelType;
// Define ICU channels

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
 * Index : 8.2.4 [SWS_Icu_00280]
 * Description : This type contains initialization data.
 */

struct Icu_ConfigType {
    // Hw dependent
};
typedef struct Icu_ConfigType Icu_ConfigType;

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
typedef Icu_DutyCycleType Icu_DutyCycleType;

/*
 * Index : 8.2.8 [SWS_Icu_00292]
 * Description : Type, to abstract the return value of the service Icu_GetTimestampIndex().
 */
typedef uint8 Icu_IndexType;

/*
 * Index : 8.2.9 [SWS_Icu_00293]
 * Description : Type, to abstract the return value of the service Icu_GetEdgeNumbers().
 */
typedef uint8 cu_EdgeNumberType;


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
    CU_LINEAR_BUFFER,
    ICU_CIRCULAR_BUFFER 
};
typedef Icu_TimestampBufferType Icu_TimestampBufferType;

#endif /* ICU_TYPES_H */
