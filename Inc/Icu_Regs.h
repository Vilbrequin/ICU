#ifndef ICU_REGS_H_
#define ICU_REGS_H

// PCC Base Address
#define PCC_BASE_ADDRESS                    0x40065000
#define PCC_CGC_BIT                         30U /* Clock Gate Control: enables the clock for the peripheral */

#define PCC_FTM_0_OFFSET                    0xE0
#define PCC_FTM_0                           (PCC_BASE_ADDRESS + PCC_FTM_0_OFFSET)

#define PCC_FTM_1_OFFSET                    0xE4
#define PCC_FTM_1                           (PCC_BASE_ADDRESS + PCC_FTM_1_OFFSET)

#define PCC_FTM_2_OFFSET                    0xE8
#define PCC_FTM_2                           (PCC_BASE_ADDRESS + PCC_FTM_2_OFFSET)

#define PCC_FTM_3_OFFSET                    0x98
#define PCC_FTM_3                           (PCC_BASE_ADDRESS + PCC_FTM_3_OFFSET)

// FTM Instances Base Addresses
#define FTM_0_BASSE_ADDRESS                 0x40038000
#define FTM_1_BASSE_ADDRESS                 0x40039000
#define FTM_2_BASSE_ADDRESS                 0x4003A000
#define FTM_3_BASSE_ADDRESS                 0x40026000

/* 
Status And Control (CS) Register Base address
SC contains the overflow status flag and control bits used to configure the interrupt
enable, FTM configuration, clock source, filter prescaler, and prescaler factor. 
*/
#define SC_OFFSET                           0x00
#define FTM_0_SC                            (FTM_0_BASSE_ADDRESS + SC_OFFSET)
#define FTM_1_SC                            (FTM_1_BASSE_ADDRESS + SC_OFFSET)
#define FTM_2_SC                            (FTM_2_BASSE_ADDRESS + SC_OFFSET)
#define FTM_3_SC                            (FTM_3_BASSE_ADDRESS + SC_OFFSET)


/*
Counter (CNT) Base Address
The CNT register contains the FTM counter value. 
*/
#define CNT_OFFSET                          0x04
#define FTM_0_CNT                           (FTM_0_BASSE_ADDRESS + CNT_OFFSET)
#define FTM_1_CNT                           (FTM_1_BASSE_ADDRESS + CNT_OFFSET)
#define FTM_2_CNT                           (FTM_2_BASSE_ADDRESS + CNT_OFFSET)
#define FTM_3_CNT                           (FTM_3_BASSE_ADDRESS + CNT_OFFSET)

/*
Modulo (MOD) Register
The MOD register defines the upper limite for the FTM counter.
*/
#define MOD_OFFSET                          0x08
#define FTM_0_MOD                           (FTM_0_BASSE_ADDRESS + MOD_OFFSET)
#define FTM_1_MOD                           (FTM_1_BASSE_ADDRESS + MOD_OFFSET)
#define FTM_2_MOD                           (FTM_2_BASSE_ADDRESS + MOD_OFFSET)
#define FTM_3_MOD                           (FTM_3_BASSE_ADDRESS + MOD_OFFSET)

/*
Conter Initial Value (CNTIN)
The CNTIN register caontains the initial value for the FTM counter.
*/
#define CNTIN_OFFSET                        0x4C
#define FTM_0_CNTIN                         (FTM_0_BASSE_ADDRESS + CNTIN_OFFSET)
#define FTM_1_CNTIN                         (FTM_1_BASSE_ADDRESS + CNTIN_OFFSET)
#define FTM_2_CNTIN                         (FTM_2_BASSE_ADDRESS + CNTIN_OFFSET)
#define FTM_3_CNTIN                         (FTM_3_BASSE_ADDRESS + CNTIN_OFFSET)

/*
Capture and Compare Status (STATUS)
The STATUS register contains a copy of the status flag CHF bit in CnSC for each FTM
channel for software convenience.
*/
#define STATUS_OFFSET                       0x50
#define FTM_0_STATUS                        (FTM_0_BASSE_ADDRESS + STATUS_OFFSET)
#define FTM_1_STATUS                        (FTM_1_BASSE_ADDRESS + STATUS_OFFSET)
#define FTM_2_STATUS                        (FTM_2_BASSE_ADDRESS + STATUS_OFFSET)
#define FTM_3_STATUS                        (FTM_3_BASSE_ADDRESS + STATUS_OFFSET)

/*
Features Mode Selection (MODE)
This register contains the global enable bit for FTM-specific features.
Important fields: MODE[WPDIS] and MODE[FTMEN], for updating registers (MOD, CNTIN)
from write buffers
*/
#define MODE_OFFSET                         0x54
#define FTM_0_MODE                          (FTM_0_BASSE_ADDRESS + STATUS_OFFSET)
#define FTM_1_MODE                          (FTM_1_BASSE_ADDRESS + STATUS_OFFSET)
#define FTM_2_MODE                          (FTM_2_BASSE_ADDRESS + STATUS_OFFSET)
#define FTM_3_MODE                          (FTM_3_BASSE_ADDRESS + STATUS_OFFSET)

/*
Input Capture Filter Control (FILTER)
This register selects the filter value for the inputs of channels, the filter is
only available on channels 0, 1, 2, and 3.
When there is a state change in the channel input, the counter is reset and starts counting
up. As long as the new state is stable on the channel input, the counter continues to
increment. When the counter is equal to CHnFVAL[3:0], the new channel input signal
value is validated. It is then transmitted as a pulse to the edge detector.
*/
#define FILTER_OFFSET                       0x78
#define FTM_0_FILTER                        (FTM_0_BASSE_ADDRESS + FILTER_OFFSET)
#define FTM_1_FILTER                        (FTM_1_BASSE_ADDRESS + FILTER_OFFSET)
#define FTM_2_FILTER                        (FTM_2_BASSE_ADDRESS + FILTER_OFFSET)
#define FTM_3_FILTER                        (FTM_3_BASSE_ADDRESS + FILTER_OFFSET)

/*
This register contains the configuration bits for each pair of channels.
DECAPEN: Dual Edge Capture Enable, Enables Dual Edge Capture Mode, which captures timestamps on both rising and falling edges
MCOMBINE: Modified Combine Mode, used in PWM and Combined Mode, where two channels are linked together to generate synchronized signals
COMBINE: Combine Channels, Allows two adjacent channels to be combined for complex PWM generation.
*/
#define COMBINE_OFFSET                  0x64
#define FTM_0_COMBINE                       (FTM_0_BASSE_ADDRESS + COMBINE_OFFSET)
#define FTM_1_COMBINE                       (FTM_1_BASSE_ADDRESS + COMBINE_OFFSET)
#define FTM_2_COMBINE                       (FTM_2_BASSE_ADDRESS + COMBINE_OFFSET)
#define FTM_3_COMBINE                       (FTM_3_BASSE_ADDRESS + COMBINE_OFFSET)

#endif /* ICU_REGS_H */