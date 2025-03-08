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
#define DIO_MODULE_ID                              (122U)
#define DIO_MODULE_INSTANCE_ID                     (0U)
#define DIO_MODULE_VENDOR_ID                       (0xD0) /* My own vendor id (company dependent): highest vid is 0xC7(Real-Time Innovations)*/

/* Module version 1.0.0 */
#define ICU_MODULE_MAJOR_VERSION                   (1U)
#define ICU_MODULE_MINOR_VERSION                   (0U)
#define ICU_MODULE_PATCH_VERSION                   (0U)

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


#endif /* ICU_H_*/