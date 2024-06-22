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


/*
void R_CGC_Create(void)
{
    volatile uint32_t w_count;
    uint8_t           temp_stab_set;
    uint8_t           temp_stab_wait;

    // Set fMX
    CMC = _40_CGC_HISYS_OSC | _10_CGC_SUB_OSC | _01_CGC_SYSOSC_OVER10M | _02_CGC_SUBMODE_NORMAL;
    OSTS = _07_CGC_OSCSTAB_SEL18;
    MSTOP = 0U;
    temp_stab_set = _FF_CGC_OSCSTAB_STA18;

    do
    {
        temp_stab_wait = OSTC;
        temp_stab_wait &= temp_stab_set;
    }
    while (temp_stab_wait != temp_stab_set);

    // Set fMAIN
    MCM0 = 0U;
    // Set fSUB
    XTSTOP = 0U;

    // Change the waiting time according to the system
    for (w_count = 0U; w_count <= CGC_SUBWAITTIME; w_count++)
    {
        NOP();
    }

    OSMC = _00_CGC_SUBINHALT_ON | _00_CGC_RTC_CLK_FSUB;
    // Set fCLK
    CSS = 0U;
    // Set fIH
    HIOSTOP = 0U;
}
*/

/*
    //Oscillation stabilization time counter status register (OSTC)
// Oscillation stabilization time status (MOST18 - MOST8)
#define _00_CGC_OSCSTAB_STA0        (0x00U) // < 2^8/fX
#define _80_CGC_OSCSTAB_STA8        (0x80U) // 2^8/fX
#define _C0_CGC_OSCSTAB_STA9        (0xC0U) // 2^9/fX
#define _E0_CGC_OSCSTAB_STA10       (0xE0U) // 2^10/fX
#define _F0_CGC_OSCSTAB_STA11       (0xF0U) // 2^11/fX
#define _F8_CGC_OSCSTAB_STA13       (0xF8U) // 2^13/fX
#define _FC_CGC_OSCSTAB_STA15       (0xFCU) // 2^15/fX
#define _FE_CGC_OSCSTAB_STA17       (0xFEU) // 2^17/fX
#define _FF_CGC_OSCSTAB_STA18       (0xFFU) // 2^18/fX


//    Oscillation stabilization time select register (OSTS)

// Oscillation stabilization time selection (OSTS2 - OSTS0)
#define _00_CGC_OSCSTAB_SEL8        (0x00U) // 2^8/fX
#define _01_CGC_OSCSTAB_SEL9        (0x01U) // 2^9/fX
#define _02_CGC_OSCSTAB_SEL10       (0x02U) // 2^10/fX
#define _03_CGC_OSCSTAB_SEL11       (0x03U) // 2^11/fX
#define _04_CGC_OSCSTAB_SEL13       (0x04U) // 2^13/fX
#define _05_CGC_OSCSTAB_SEL15       (0x05U) // 2^15/fX
#define _06_CGC_OSCSTAB_SEL17       (0x06U) // 2^17/fX
#define _07_CGC_OSCSTAB_SEL18       (0x07U) // 2^18/fX
 */
