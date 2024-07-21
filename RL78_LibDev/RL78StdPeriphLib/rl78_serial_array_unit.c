//
//			Filename: rl78_serial_array_unit.c
//          Library for configuration and usage of the Serial Array Unit (SAU)
//
//			Complete clean-room design from the datasheet
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



// UART Mode put, get functions
//---------------------------------


// Name: putUARTChar
// Function: Transmit character on UART
void putUARTChar(unsigned char c){

	while (SSR00 != 0){
		;					// be careful here... OV, NF flags might be set trapping it here forever...
	}
	SIO00 = c;		// (SIO00 causes compiler to do lower 8-bit write on SDR00)


}


//-----------------------------------------------------------------------------------------
// Name: ConfigSerialArray
// Function: Configure Serial Array for desired functionality
// Parameters: Array number (0 = SAU0, 1 = SAU1)
//             Struct containing parameters
// Returns: Result of operation: -1 if error, 0 = success
//-----------------------------------------------------------------------------------------
int ConfigSerialArray(uint8_t unit, sau_config_struct *config){

	//unsigned int test;
	switch (unit){

	case 0:

		switch(config->mode){

		case UART_Mode:
				// UART mode is specified, set up accordingly

				InitSAU0(config->prescale_ck00, config->prescale_ck01); // This will be baudrate dependent

				// Channel 0 set as Tx
				SMR00 = SMR_keeper | UART_Mode_Select;
				SCR00 = (transmit_only | config->parity | SCR00_keeper | lsb_first | config->transfer_length | config->stop_bits);
				SDR00 = baud_const_9600;

				// Channel 1 set as Rx
				SMR01 = (SMR_keeper | STSmn | UART_Mode_Select);
				SCR01 = (receive_only | config->parity | SCR00_keeper | lsb_first | config->transfer_length | config->stop_bits | config->error_irq_setting);
				SDR01 = baud_const_9600; // check that the timing is correct... could be because parity was used with the "sample" code

				// Port pins configured for UART
				SO0 = 0x01;					// TxD idle is '1'
				SOE0 = 0x01;				// Enable TxD
				P1_bit.no2 = 1;				// P1.2 output level set to logic 1
				PM1_bit.no1 = 1;			// P1.1 is input (for RxD)
				PM1_bit.no2 = 0;			// P1.2 is output (for TxD)

				// Start transmit section
				IF0H = 0x00; 				// ensure interrupts are off for now
				MK0H = 0x00;				// ensure interrupt masks clear
				SS0 = 0x03;					// Set bits SS01:SS00 to enable transmitter
				return 0;

		}

		break;


	case 1:


		break;


	default:
		return -1;

	}

	return -1;
}


// Name: InitSAU0
// Function: Initialise Serial Array Unit 0
// Parameters: Divisor for clock Prescaler 0 (CK00), Divisor for clock Prescaler 1 (CK01)
//   Where the two prescalers apply to channels 0, 1 and 2, 3 respectively
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
// Parameters: Divisor for clock Prescaler 0, Divisor for clock Prescaler 1
//   Where the two prescalers apply to channels 0, 1 and 2, 3 respectively
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

//-----------------------------------------------------------------------------------------------------------------
// Name: ConfigSAU0
// Function: Configure Serial Array Unit 0
// Parameters: Configuration for Channel pair 0 & 1, Configuration for Channel pair 2 & 3
//         Channel pairs are bonded together to implement a function e.g. 0 & 1 or 2 & 3 for UARTs
//           whereas single channels can work for other interfaces e.g. Ch 0 for CSI (SPI) and Ch 3 for Simple I2C
// Returns: Result 0 if successful, -1 otherwise
//-----------------------------------------------------------------------------------------------------------------
int ConfigSAU0(uint8_t mode_p1, uint8_t mode_p2){


	// Configuration for channel pair 0 & 1
	switch(mode_p1){
	case CSI_Mode:

		break;

	case UART_Mode:
		// Channel 0 set up as transmit path
		SMR00 = 0x22;
		SCR00 = 0x8097;	 //  was 8297 TXE=1 (Transmit only) PTCmn1=1 PTCmn0=0 (even parity) , DIR=1 (lsb first) 1 stop bit, 8 bits transmitted
		SDR00 = 0xF700;	 // Upper 8 bits set baudrate  WAS 0xC7

		// Channel 1 set up as receive path
		SMR01 = 0x122;
		SCR01 = 0x4497;   // was 4697
		SDR01 = 0xFE00;  // Upper 8 bits set baudrate  was 0xCE

		// Port pins configured for UART
		SO0 = 0x01;					// TxD idle is '1'
		SOE0 = 0x01;				// Enable TxD
		P1_bit.no2 = 1;				// P1.2 output level set to logic 1
		PM1_bit.no1 = 1;			// P1.1 is input (for RxD)
		PM1_bit.no2 = 0;			// P1.2 is output (for TxD)

		// Start transmit section
		IF0H = 0x00; 				// ensure interrupts are off for now
		MK0H = 0x00;				// ensure interrupt masks clear
		SS0 = 0x03;					// Set bits SS01:SS00 to enable transmitter

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

