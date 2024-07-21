//-----------------------------------------------------------------------------------------------------
//
//
//					Filename: rl78_g13.h
//					Header file for the RL78/G13 microcontroller
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
//
//-----------------------------------------------------------------------------------------------------

#ifndef RL78_G13_H_
#define RL78_G13_H_



// Bit position definitions
//-------------------------

// This declares bit position masks as we use logical-OR operations to create the
// OPTION bytes

#define BIT0                   (0x0001)
#define BIT1                   (0x0002)
#define BIT2                   (0x0004)
#define BIT3                   (0x0008)
#define BIT4                   (0x0010)
#define BIT5                   (0x0020)
#define BIT6                   (0x0040)
#define BIT7                   (0x0080)


// OPTION bit definitions
//-----------------------
// Byte 1
#define WDTOFF  			0                   // Completely turned off
#define WDT_DEFAULT			(WDTINIT | WDSTBYON)	// <--- default setting used by the Renesas toolchain project wizard

// Byte 2
#define LVDOFF				(VPOC2 | LVIMDS0 | OPTION_B2_KEEPER)		// Turned off, as per datasheet

// Byte 3
#define HIGHSPEED_INT_32MHZ (HS_MODE | OPTION_B3_KEEPER | CLK_32MHZ)
#define HIGHSPEED_INT_24MHZ (HS_MODE | OPTION_B3_KEEPER | CLK_24MHZ)
#define HIGHSPEED_INT_16MHZ (HS_MODE | OPTION_B3_KEEPER | CLK_16MHZ)
#define HIGHSPEED_INT_12MHZ (HS_MODE | OPTION_B3_KEEPER | CLK_12MHZ)
#define HIGHSPEED_INT_8MHZ (HS_MODE | OPTION_B3_KEEPER | CLK_8MHZ)
#define HIGHSPEED_INT_4MHZ (HS_MODE | OPTION_B3_KEEPER | CLK_4MHZ)
#define HIGHSPEED_INT_1MHZ (HS_MODE | OPTION_B3_KEEPER | CLK_1MHZ)
#define LOWSPEED_INT_8MHZ	(LS_MODE | OPTION_B3_KEEPER | CLK_8MHZ)
#define LOWSPEED_INT_4MHZ	(LS_MODE | OPTION_B3_KEEPER | CLK_4MHZ)
#define LOWSPEED_INT_1MHZ	(LS_MODE | OPTION_B3_KEEPER | CLK_1MHZ)
#define LOWPOWER_INT_4MHZ	(LP_MODE | OPTION_B3_KEEPER | CLK_4MHZ)
#define LOWPOWER_INT_1MHZ	(LP_MODE | OPTION_B3_KEEPER | CLK_1MHZ)

// Byte 4

#define DEBUGGING_DISABLED 				 (OPTION_B4_KEEPER | DISABLE_DEBUG)
#define DEBUGGING_ENABLED_WRITE_PROTECT  (OPTION_B4_KEEPER | DEBUG_FLASH_WP)    // <--- default by RL78 toolchain
#define DEBUGGING_ENABLED				 (OPTION_B4_KEEPER | DEBUG_FLASH_ERASABLE)



#define WDTINIT				(0x0080)
#define WINDOW1				(0x0040)
#define WINDOW0             (0x0020)
#define WDTON				(0x0010)
#define WDCS2				(0x0008)
#define WDCS1				(0x0004)
#define WDCS0				(0x0002)
#define WDSTBYON			(0x0001)

#define VPOC2				(0x0080)
#define VPOC1				(0x0040)
#define VPOC0				(0x0020)
#define OPTION_B2_KEEPER	(0x0010)		//<-- the bit that must always be set
#define LVIS1				(0x0008)
#define LVIS0				(0x0004)
#define LVIMDS1				(0x0002)
#define LVIMDS0				(0x0001)

#define CMODE1				(0x0080)
#define CMODE0				(0x0040)
#define OPTION_B3_KEEPER	(0x0020)		//<-- the bit that must always be set
#define FRQSEL3				(0x0008)
#define FRQSEL2				(0x0004)
#define FRQSEL1				(0x0002)
#define FRQSEL0				(0x0001)

#define HS_MODE				(CMODE1 | CMODE0)
#define LS_MODE				(CMODE1)
#define LP_MODE				0

#define CLK_32MHZ			(FRQSEL3)
#define CLK_24MHZ			0
#define CLK_16MHZ			(FRQSEL3 | FRQSEL0)
#define CLK_12MHZ			(FRQSEL0)
#define CLK_8MHZ			(FRQSEL3 | FRQSEL1)
#define CLK_4MHZ			(FRQSEL3 | FRQSEL1 | FRQSEL0)
#define CLK_1MHZ			(FRQSEL3 | FRQSEL2 | FRQSEL0)


#define OCDENSET			(0x0080)
#define OPTION_B4_KEEPER	(0x0004)		//<-- the bit that must always be set
#define OCDERSD				(0x0001)

#define DISABLE_DEBUG		    0
#define DEBUG_FLASH_ERASABLE	(OCDENSET)
#define DEBUG_FLASH_WP		    (OCDENSET | OCDERSD)

//-----------------------------------------------------------------
// Clock Generator System
// Registers that are not bit addressable
//-----------------------------------------------------------------

// CMC Register Bit Definitions
//---------------------------------

#define X1_PINS_GPIO		(0x0000)
#define X1_OSCILLATOR		(0x0040)
#define X1_EXTERNAL_CLK 	(0x00C0)
#define XT1_PINS_GPIO   	(0x0000)
#define XT1_OSCILLATOR		(0x0010)
#define XT1_EXTERNAL_CLK 	(0x0030)

#define X1_LOWSPD		(0x0000)
#define X1_HIGHSPD		(0x0001)
#define XT1_LOWPWR		(0x0000)
#define XT1_NORM		(0x0002)
#define XT1_ULP			(0x0004)

// Oscillator stabilisation wait period constants
//-----------------------------------------------
#define STAB_WAIT_0		0x00		// WT= 25.6uS / 12.8uS
#define STAB_WAIT_1 	0x01
#define STAB_WAIT_2		0x02
#define STAB_WAIT_3		0x03
#define STAB_WAIT_4		0x04
#define STAB_WAIT_5		0x05
#define STAB_WAIT_6		0x06
#define STAB_WAIT_7		0x07		// WT = 26.21mS / 13.11mS

// Oscillator stabilisation flags (OSTC register)
// The bit pattern that would be set corresponds to the time constant written to OSTS
// as per the above table
//-------------------------------------------------------------------------------------
#define OSCSTAB_DEFAULT      (0x00U) // < 2^8/fX
#define OSCSTAB_WAIT_0       (0x80U) // 2^8/fX
#define OSCSTAB_WAIT_1       (0xC0U) // 2^9/fX
#define OSCSTAB_WAIT_2       (0xE0U) // 2^10/fX
#define OSCSTAB_WAIT_3       (0xF0U) // 2^11/fX
#define OSCSTAB_WAIT_4       (0xF8U) // 2^13/fX
#define OSCSTAB_WAIT_5       (0xFCU) // 2^15/fX
#define OSCSTAB_WAIT_6       (0xFEU) // 2^17/fX
#define OSCSTAB_WAIT_7       (0xFFU) // 2^18/fX

// OSMC Register macros
//----------------------
#define RTCLPC				(0x80U)
#define WUTMMCK0			(0x10U)

// ITMC Register macros
//---------------------
#define RINTE				(0x8000)


// SAU Register macros
//---------------------
#define CKSmn						(0x8000)
#define CCSmn						(0x4000)
#define STSmn						(0x0100)
#define SISmn0						(0x0040)
#define SMR_keeper					(0x0020)
#define MDmn2						(0x0004)
#define MDmn1						(0x0002)
#define MDmn0						(0x0001)
#define CSI_Mode_Select				(0x0000)
#define UART_Mode_Select			(0x0002)
#define SimpleI2C_Mode_Select		(0x0004)
#define BufEmptyIRQ					(0x0001)

// SCR00 Register macros
//------------------------

#define TXEmn						(0x8000)
#define RXEmn						(0x4000)
#define DAPmn						(0x2000)
#define CKPmn						(0x1000)
#define EOCmn						(0x0400)
#define PTCmn1						(0x0200)
#define PTCmn0						(0x0100)
#define DIRmn						(0x0080)
#define SLCmn1						(0x0020)
#define SLCmn0						(0x0010)
#define SCR00_keeper				(0x0004)
#define DLSmn1						(0x0002)
#define DLSmn0						(0x0001)

// TXE & RXE bits
#define disable_comm				(0x0000)
#define receive_only				(0x4000)
#define transmit_only				(0x8000)
#define duplex						(0xC000)

// DAP and CKP bits
#define phase_type_1				(0x0000)
#define phase_type_2				(0x1000)
#define phase_type_3				(0x2000)
#define phase_type_4				(0x3000)

#define enable_INTSREx				(0x0400)

#define parity_none					(0x0000)
#define parity_zero					(0x0100)
#define parity_even					(0x0200)
#define parity_odd					(0x0300)

#define lsb_first					(0x0080)
#define no_stop_bits					(0x0000)
#define one_stop_bits				(0x0010)
#define two_stop_bits				(0x0020)

#define bit_xfr_9_bits				(0x0001)
#define bit_xfr_7_bits				(0x0002)
#define bit_xfr_8_bits				(0x0003)



#endif /* RL78_G13_H_ */
