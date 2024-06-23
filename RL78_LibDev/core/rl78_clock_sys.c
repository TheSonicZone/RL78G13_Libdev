//
//			Filename: rl78_clock_sys.c
//          Clock System Control Functions
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
#include "../core/rl78_clock_sys.h"
#include "../core/iodefine.h"
#include "../core/iodefine_ext.h"

//-------------------------------------------------------------------------------------------
// Name: SetCPUClockX1
// Function: Set the CPU clock to the xtal oscillator X1 and turn off the on-chip oscillator
// Parameters: void
// Returns: void
//--------------------------------------------------------------------------------------------
void SetCPUClockX1(void){
	CSS = 0;
	MCM0 = 1;
	HIOSTOP = 1;
}

//--------------------------------------------------------------------------------------------
// Name: InitClockSys
// Function: Initialise the clock system per the provided parameters
//           if EXT clock oscillator is used, this function will set the alternate function
//           on the appropriate GPIO pins
// Parameters: Main Clock Mode, Subsystem Clock Mode
// Returns: Result of operation
//--------------------------------------------------------------------------------------------
int InitClockSystem(unsigned char main_mode, unsigned char subsystem_mode){

	uint8_t CMC_Value = 0;
	uint8_t OSTC_Value = 0;
	uint8_t OSTC_Comparison_Value = 0;
	uint32_t XT1DelayCounter;

	PIOR = 0x00;			// Peripheral I/O redirections cleared

	// Main clock source setting
	switch(main_mode){

	case ONCHIP_HS:			// HS on-chip oscillator mode, make sure the clock speed is set in OPTION
		CMC_Value = X1_PINS_GPIO;
		break;

	case X1_NORMAL:
		// External X1 oscillator is requested, prepare bit settings for write-once register CMC
		CMC_Value = X1_OSCILLATOR | X1_LOWSPD;
		break;
	case X1_HIGHSPEED:
		CMC_Value = X1_OSCILLATOR | X1_HIGHSPD;
		break;

	case X1_EXTERNAL:
		CMC_Value = X1_EXTERNAL_CLK;
		break;

	default:
		return -1;		// invalid value, return -1

	}

	// Sub clock source setting
	switch(subsystem_mode){
	case ONCHIP_LS:
		CMC_Value = CMC_Value | XT1_PINS_GPIO;
		break;

	case XT1_LOWPOWER:
		CMC_Value = CMC_Value | XT1_OSCILLATOR | XT1_LOWPWR;
		break;

	case XT1_NORMAL:
		CMC_Value = CMC_Value | XT1_OSCILLATOR | XT1_NORM;
		break;

	case XT1_ULTRALOW:
		CMC_Value = CMC_Value | XT1_OSCILLATOR | XT1_ULP;
		break;

	case XT1_EXTERNAL:
		CMC_Value = CMC_Value | XT1_EXTERNAL_CLK;
		break;

	default:
		return -1;		// invalid value, return -1


	}

	// Various bit settings were prepared, now we can write to write-once register CMC
	CMC = CMC_Value;


	if(main_mode != ONCHIP_HS && main_mode != X1_EXTERNAL){
		// Set up oscillator stabilization timer for main clock oscillator XT
		//--------------------------------------------------------------------------------
		OSTS = STAB_WAIT_7;  // Set longest wait period
		MSTOP = 0x00;		 // Clear MSTOP bit in CSC register

		// Poll OSTC, it should equal a specific constant value as defined in the header, when
		// the stabilisation time is over
		//-------------------------------------------------------------------------------------
		OSTC_Comparison_Value = OSCSTAB_WAIT_7;
		for(;;){
			OSTC_Value = OSTC;						// Read OSTC
			OSTC_Value &= OSTC_Comparison_Value;	// AND it with mask comparison value
			if(OSTC_Value == OSTC_Comparison_Value){
				break;
			}

		};
	}

	if(subsystem_mode != ONCHIP_LS && subsystem_mode != XT1_EXTERNAL){
		// Enable sub clock oscillator XT1
		//---------------------------------
		XTSTOP = 0;

		// Wait for the sub-clock oscillator to stabilise
		//-----------------------------------------------
		for(XT1DelayCounter = 0; XT1DelayCounter <= XT1_Stab_Time; XT1DelayCounter++){
			NOP();
		}

	}
	// Enable clock distribution
	//--------------------------
	OSMC = RTCLPC | WUTMMCK0;
	CSS = 0;					// CPU clock is set to Fmain
	return 0;
}





