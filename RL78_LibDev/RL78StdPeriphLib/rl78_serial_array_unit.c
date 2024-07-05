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
// Parameters: Divisor for Prescaler 0, Divisor for prescaler 1
// Returns: 0 if successful, -1 if error
//--------------------------------------------------------------------------------------
int InitSAU0(uint8_t divide_m0, uint8_t divide_m1){

	uint16_t SPS_Value = 0;
	SAU0EN = 1;				// Enable clock to SAU 0
	SPS_Value = (uint16_t)divide_m1;
	SPS_Value <<= 4;
	SPS_Value |= (uint16_t)divide_m0;
	SPS0 = SPS_Value;
	return 0;
}

// Name: InitSAU1
// Function: Initialise Serial Array Unit 1
// Parameters: Divisor for Prescaler 0, Divisor for prescaler 1
// Returns: 0 if successful, -1 if error
//--------------------------------------------------------------------------------------
int InitSAU1(uint8_t divide_m0, uint8_t divide_m1){

	uint16_t SPS_Value = 0;
	unsigned char package = device;
	if(package == package_20_pin || package == package_24_pin || package == package_25_pin){
		// The package types checked for do not contain SAU1 hence we return with an error
		return -1;
	}
	SAU1EN = 1;				// Enable clock to SAU 1
	SPS_Value = (uint16_t)divide_m1;
	SPS_Value <<= 4;
	SPS_Value |= (uint16_t)divide_m0;
	SPS1 = SPS_Value;
	return 0;
}


// Name: ConfigSAU0
// Function: Configure Serial Array Unit 0
// Parameters: Configuration for Channels 0 & 1, Configuration for Channels 2 & 3
//         Channel pairs are bonded together to implement a function e.g. 0 & 1 or 2 & 3 for UARTs
//           whereas single channels can work for other interfaces e.g. Ch 0 for CSI (SPI) and Ch 3 for Simple I2C
// Returns: Result 0 if successful, -1 otherwise
//-----------------------------------------------------------------------------------------------------------------
int ConfigSAU0(uint8_t mode_p1, uint8_t mode_p2){

	// Configuration affecting channels 0, 1
	switch(mode_p1){
	case CSI_Mode:

		break;

	case UART_Mode:

		break;

	case SimpleI2C_Mode:
		break;

	default:
		return -1;
	}

	// Configuration affecting channels 2, 3
	switch(mode_p2){
	case CSI_Mode:

		break;

	case UART_Mode:

		break;

	case SimpleI2C_Mode:

		break;

	default:
		return -1;
	}

	return -1;
}

