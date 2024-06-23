//
//			Filename: rl78_interval_timer.c
//          Library for configuration and usage of interval timer
//
//			Small portions based on code provided by Renesas Electronics via Appilet
//          (changed for ease of use and logical functionality)
//
//			Copyright (C) 2024  The Sonic Zone (PTY) LTD
//
//			This program is free software: you can redistribute it and/or modify
//			it under the terms of the GNU General Public License as published by
//			the Free Software Foundation, either version 3 of the License, or
//			(at your option) any later version.
//
//			This program is distributed in the hope that it will be useful,
//			but WITHOUT ANY WARRANTY; without even the implied warranty of
//			MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//			GNU General Public License for more details.
//
//			You should have received a copy of the GNU General Public License
//			along with this program.  If not, see <http://www.gnu.org/licenses/>.
//---------------------------------------------------------------------------------------
#include <inttypes.h>
#include "../core/rl78_g13.h"
#include "../core/iodefine.h"
#include "../core/iodefine_ext.h"
#include "../RL78StdPeriphLib/rl78_interval_timer.h"


//---------------------------------------------------------------------------------------
// Name: InitIntervalTimer
// Function: Configure and enable Interval Timer
//
// Prerequisites: Bit WUTMMCK0 must be set in OSMC to use this module
//---------------------------------------------------------------------------------------
void InitIntervalTimer(uint16_t period){
	uint16_t config_value = 0;
	uint8_t osmc_read;

	// Change clock configuration- clock this module from the 32.768kHz crystal
	osmc_read = OSMC;						// Read OMSC register
	osmc_read &= ~WUTMMCK0;					// Clear WUTMMCK0 bit
	OSMC = osmc_read;						// Write modified value back

	RTCEN = 1 ;								// Enable clock to RTC Subsystem (RTC, Interval timer)

	config_value = period & 0x0FFF;			// Mask off the uppermost 4 bits as they are control bits
	config_value |= RINTE;					// Set RINTE bit to let the timer run
	ITMC = config_value;					// Timer is started
	ITIF = 0;								// Clear interrupt flag

	// If interrupts are desired, unmask the interrupt for this peripheral

}



