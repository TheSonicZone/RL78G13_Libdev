//
//			Filename: rl78_serial_array_unit.c
//          Library for configuration and usage of the Serial Array Unit (SAU)
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
#include "../core/devicetype.h"
#include "../core/rl78_g13.h"
#include "../core/iodefine.h"
#include "../core/iodefine_ext.h"
#include "../RL78StdPeriphLib/rl78_serial_array_unit.h"


// Name: InitSAU0
// Function: Initialise Serial Array Unit 0
// Parameters: Clock value
// Returns: void
//--------------------------------------------------------------------------------------
void InitSAU0(uint16_t clock){

	SAU0EN = 1;				// Enable clock to SAU 0
	SPS0 = clock;     // This register is two 4 bit fields << TODO: FIX

}

// Name: InitSAU1
// Function: Initialise Serial Array Unit 1
// Parameters: Clock value
// Returns: void
//--------------------------------------------------------------------------------------
void InitSAU1(uint16_t clock){

	SAU1EN = 1;				// Enable clock to SAU 1
	SPS1 = clock;

}


// Name: InitSAU0_Channel0
// Function: Initialise SAU 0 Channel 0
// Parameters: Operation mode
//-----------------------------------------------------------------------------------------
void InitSAU0_Channel0(uint8_t mode){

	uint16_t SMR_Mode = 0;

	switch (mode){
	case CSI_Mode:
		break;
	case UART_Mode:
		break;

	}


	SMR00 = 0x0000;




}

