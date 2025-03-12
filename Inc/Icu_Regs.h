#ifndef ICU_REGS_H_
#define ICU_REGS_H

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
Counter (CTN) Base Address
The CNT register contains the FTM counter value. 
*/
#define CTN_OFFSET                          0x04
#define FTM_0_CTN                           (FTM_0_BASSE_ADDRESS + CTN_OFFSET)
#define FTM_1_CTN                           (FTM_1_BASSE_ADDRESS + CTN_OFFSET)
#define FTM_2_CTN                           (FTM_2_BASSE_ADDRESS + CTN_OFFSET)
#define FTM_3_CTN                           (FTM_3_BASSE_ADDRESS + CTN_OFFSET)

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
Channel (n) Status And Control (C0SC - C7SC)
CnSC contains channel (n) status bits and control bits that select the channel (n) mode
and its functionality.
*/
// Channel 0 Status And Control
#define C0SC_OFFSET                         0x0C + (0 * 0x08)
#define FTM_0_C0SC                          (FTM_0_BASSE_ADDRESS + C0SC_OFFSET)
#define FTM_1_C0SC                          (FTM_1_BASSE_ADDRESS + C0SC_OFFSET)
#define FTM_2_C0SC                          (FTM_2_BASSE_ADDRESS + C0SC_OFFSET)
#define FTM_3_C0SC                          (FTM_3_BASSE_ADDRESS + C0SC_OFFSET)

// Channel 1 Status And Control
#define C1SC_OFFSET                         0x0C + (1 * 0x08)
#define FTM_0_C1SC                          (FTM_0_BASSE_ADDRESS + C1SC_OFFSET)
#define FTM_1_C1SC                          (FTM_1_BASSE_ADDRESS + C1SC_OFFSET)
#define FTM_2_C1SC                          (FTM_2_BASSE_ADDRESS + C1SC_OFFSET)
#define FTM_3_C1SC                          (FTM_3_BASSE_ADDRESS + C1SC_OFFSET)

// Channel 2 Status And Control
#define C2SC_OFFSET                         0x0C + (2 * 0x08)
#define FTM_0_C2SC                          (FTM_0_BASSE_ADDRESS + C2SC_OFFSET)
#define FTM_1_C2SC                          (FTM_1_BASSE_ADDRESS + C2SC_OFFSET)
#define FTM_2_C2SC                          (FTM_2_BASSE_ADDRESS + C2SC_OFFSET)
#define FTM_3_C2SC                          (FTM_3_BASSE_ADDRESS + C2SC_OFFSET)

// Channel 3 Status And Control
#define C3SC_OFFSET                         0x0C + (3 * 0x08)
#define FTM_0_C3SC                          (FTM_0_BASSE_ADDRESS + C3SC_OFFSET)
#define FTM_1_C3SC                          (FTM_1_BASSE_ADDRESS + C3SC_OFFSET)
#define FTM_2_C3SC                          (FTM_2_BASSE_ADDRESS + C3SC_OFFSET)
#define FTM_3_C3SC                          (FTM_3_BASSE_ADDRESS + C3SC_OFFSET)

// Channel 4 Status And Control
#define C4SC_OFFSET                         0x0C + (4 * 0x08)
#define FTM_0_C4SC                          (FTM_0_BASSE_ADDRESS + C4SC_OFFSET)
#define FTM_1_C4SC                          (FTM_1_BASSE_ADDRESS + C4SC_OFFSET)
#define FTM_2_C4SC                          (FTM_2_BASSE_ADDRESS + C4SC_OFFSET)
#define FTM_3_C4SC                          (FTM_3_BASSE_ADDRESS + C4SC_OFFSET)

// Channel 5 Status And Control
#define C5SC_OFFSET                         0x0C + (5 * 0x08)
#define FTM_0_C5SC                          (FTM_0_BASSE_ADDRESS + C5SC_OFFSET)
#define FTM_1_C5SC                          (FTM_1_BASSE_ADDRESS + C5SC_OFFSET)
#define FTM_2_C5SC                          (FTM_2_BASSE_ADDRESS + C5SC_OFFSET)
#define FTM_3_C5SC                          (FTM_3_BASSE_ADDRESS + C5SC_OFFSET)

// Channel 6 Status And Control
#define C6SC_OFFSET                         0x0C + (6 * 0x08)
#define FTM_0_C6SC                          (FTM_0_BASSE_ADDRESS + C6SC_OFFSET)
#define FTM_1_C6SC                          (FTM_1_BASSE_ADDRESS + C6SC_OFFSET)
#define FTM_2_C6SC                          (FTM_2_BASSE_ADDRESS + C6SC_OFFSET)
#define FTM_3_C6SC                          (FTM_3_BASSE_ADDRESS + C6SC_OFFSET)

// Channel 7 Status And Control
#define C7SC_OFFSET                         0x0C + (7 * 0x08)
#define FTM_0_C7SC                          (FTM_0_BASSE_ADDRESS + C7SC_OFFSET)
#define FTM_1_C7SC                          (FTM_1_BASSE_ADDRESS + C7SC_OFFSET)
#define FTM_2_C7SC                          (FTM_2_BASSE_ADDRESS + C7SC_OFFSET)
#define FTM_3_C7SC                          (FTM_3_BASSE_ADDRESS + C7SC_OFFSET)

/*
Channel (n) Value (C0V - C7V)
The CnV register contain the captures FTM counter value.
*/
// Channel 0 Value
#define C0V_OFFSET                          0x10 + (0 * 0x08)
#define FTM_0_C0V                           (FTM_0_BASSE_ADDRESS + C0V_OFFSET)
#define FTM_1_C0V                           (FTM_1_BASSE_ADDRESS + C0V_OFFSET)
#define FTM_2_C0V                           (FTM_2_BASSE_ADDRESS + C0V_OFFSET)
#define FTM_3_C0V                           (FTM_3_BASSE_ADDRESS + C0V_OFFSET)

// Channel 1 Value
#define C1V_OFFSET                          0x10 + (1 * 0x08)
#define FTM_0_C1V                           (FTM_0_BASSE_ADDRESS + C1V_OFFSET)
#define FTM_1_C1V                           (FTM_1_BASSE_ADDRESS + C1V_OFFSET)
#define FTM_2_C1V                           (FTM_2_BASSE_ADDRESS + C1V_OFFSET)
#define FTM_3_C1V                           (FTM_3_BASSE_ADDRESS + C1V_OFFSET)

// Channel 2 Value
#define C2V_OFFSET                          0x10 + (2 * 0x08)
#define FTM_0_C2V                           (FTM_0_BASSE_ADDRESS + C2V_OFFSET)
#define FTM_1_C2V                           (FTM_1_BASSE_ADDRESS + C2V_OFFSET)
#define FTM_2_C2V                           (FTM_2_BASSE_ADDRESS + C2V_OFFSET)
#define FTM_3_C2V                           (FTM_3_BASSE_ADDRESS + C2V_OFFSET)

// Channel 3 Value
#define C3V_OFFSET                          0x10 + (3 * 0x08)
#define FTM_0_C3V                           (FTM_0_BASSE_ADDRESS + C3V_OFFSET)
#define FTM_1_C3V                           (FTM_1_BASSE_ADDRESS + C3V_OFFSET)
#define FTM_2_C3V                           (FTM_2_BASSE_ADDRESS + C3V_OFFSET)
#define FTM_3_C3V                           (FTM_3_BASSE_ADDRESS + C3V_OFFSET)

// Channel 4 Value
#define C4V_OFFSET                          0x10 + (4 * 0x08)
#define FTM_0_C4V                           (FTM_0_BASSE_ADDRESS + C4V_OFFSET)
#define FTM_1_C4V                           (FTM_1_BASSE_ADDRESS + C4V_OFFSET)
#define FTM_2_C4V                           (FTM_2_BASSE_ADDRESS + C4V_OFFSET)
#define FTM_3_C4V                           (FTM_3_BASSE_ADDRESS + C4V_OFFSET)

// Channel 5 Value
#define C5V_OFFSET                          0x10 + (5 * 0x08)
#define FTM_0_C5V                           (FTM_0_BASSE_ADDRESS + C5V_OFFSET)
#define FTM_1_C5V                           (FTM_1_BASSE_ADDRESS + C5V_OFFSET)
#define FTM_2_C5V                           (FTM_2_BASSE_ADDRESS + C5V_OFFSET)
#define FTM_3_C5V                           (FTM_3_BASSE_ADDRESS + C5V_OFFSET)

// Channel 6 Value
#define C6V_OFFSET                          0x10 + (6 * 0x08)
#define FTM_0_C6V                           (FTM_0_BASSE_ADDRESS + C6V_OFFSET)
#define FTM_1_C6V                           (FTM_1_BASSE_ADDRESS + C6V_OFFSET)
#define FTM_2_C6V                           (FTM_2_BASSE_ADDRESS + C6V_OFFSET)
#define FTM_3_C6V                           (FTM_3_BASSE_ADDRESS + C6V_OFFSET)

// Channel 7 Value
#define C7V_OFFSET                          0x10 + (7 * 0x08)
#define FTM_0_C7V                           (FTM_0_BASSE_ADDRESS + C7V_OFFSET)
#define FTM_1_C7V                           (FTM_1_BASSE_ADDRESS + C7V_OFFSET)
#define FTM_2_C7V                           (FTM_2_BASSE_ADDRESS + C7V_OFFSET)
#define FTM_3_C7V                           (FTM_3_BASSE_ADDRESS + C7V_OFFSET)


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


#endif /* ICU_REGS_H */