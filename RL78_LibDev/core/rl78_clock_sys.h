/*
 * rl78_clock_sys.h - Header file for RL78 Clock Subsystem Library
 *
 *  Created on: 19 Jun 2024
 *      Author: Sonikku
 */

#ifndef RL78_CLOCK_SYS_H_
#define RL78_CLOCK_SYS_H_

#define XT1_Stab_Time		160

typedef enum {
	ONCHIP_HS,				// On-chip high speed oscillator
	X1_NORMAL,				// External crystal/resonator oscillator X1 normal speed (< 10MHz)
	X1_HIGHSPEED,			// External crystal/resonator oscillator X1 high speed (up to 20MHz)
	X1_EXTERNAL				// External clock source
} main_clock_modes_t;

typedef enum{
	ONCHIP_LS,				// On-chip low speed oscillator
	XT1_LOWPOWER,			// External crystal (32,768kHz) oscillator XT1 low power (default)
    XT1_NORMAL,				// External crystal (32,768kHz) oscillator XT1 normal mode
	XT1_ULTRALOW,			// External crystal (32,768kHz) oscillator XT1 ultra low power
	XT1_EXTERNAL			// External clock source

} sub_clock_modes_t;

// Function Prototypes
//-------------------------
void SetCPUClockX1(void);
int InitClockSystem(unsigned char main_mode, unsigned char subsystem_mode);

#endif /* RL78_CLOCK_SYS_H_ */
