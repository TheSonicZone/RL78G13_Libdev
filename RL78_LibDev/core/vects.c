//
//			Filename: vects.c
//          Interrupt Vectors
//			Based on boilerplate provided by Renesas Electronics and revised extensively
//          (things that do not belong here are removed - things worth saving have been kept)
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
#include "../core/interrupt_handlers.h"

// Function prototype for the reset vector
//-----------------------------------------
extern void PowerON_Reset (void);


// Linker section - reset vector
//-------------------------------
#define VEC          __attribute__ ((section (".vec")))
const void *HardwareVectors[] VEC = {
	PowerON_Reset,					// Address 0x0000
	(void*)0xFFFF
};

// Linker section - interrupt vectors
//------------------------------------
#define VECT_SECT          __attribute__ ((section (".vects")))
const void *Vectors[] VECT_SECT = {
	//INT_WDTI (0x4)
	INT_WDTI,
	//INT_LVI (0x6)
	INT_LVI,
	//INT_P0 (0x8)
	INT_P0,
	//INT_P1 (0xA)
	INT_P1,
	//INT_P2 (0xC)
	INT_P2,
	//INT_P3 (0xE)
	INT_P3,
	//INT_P4 (0x10)
	INT_P4,
	//INT_P5 (0x12)
	INT_P5,
	//INT_CSI20/INT_IIC20/INT_ST2 (0x14)
	INT_ST2,
	//INT_CSI21/INT_IIC21/INT_SR2 (0x16)
	INT_SR2,
	//INT_SRE2 (0x18)
	INT_SRE2,
	//INT_DMA0 (0x1A)
	INT_DMA0,
	//INT_DMA1 (0x1C)
	INT_DMA1,
	//INT_CSI00/INT_IIC00/INT_ST0 (0x1E)
	INT_ST0,
	//INT_CSI01/INT_IIC01/INT_SR0 (0x20)
	INT_SR0,
	//INT_SRE0/INT_TM01H (0x22)
	INT_TM01H,
	//INT_CSI10/INT_IIC10/INT_ST1 (0x24)
	INT_ST1,
	//INT_CSI11/INT_IIC11/INT_SR1 (0x26)
	INT_SR1,
	//INT_SRE1/INT_TM03H (0x28)
	INT_TM03H,
	//INT_IICA0 (0x2A)
	INT_IICA0,
	//INT_TM00 (0x2C)
	INT_TM00,
	//INT_TM01 (0x2E)
	INT_TM01,
	//INT_TM02 (0x30)
	INT_TM02,
	//INT_TM03 (0x32)
	INT_TM03,
	//INT_AD (0x34)
	INT_AD,
	//INT_RTC (0x36)
	INT_RTC,
	//INT_IT (0x38)
	INT_IT,
	//INT_KR (0x3A)
	INT_KR,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_TM04 (0x42)
	INT_TM04,
	//INT_TM05 (0x44)
	INT_TM05,
	//INT_TM06 (0x46)
	INT_TM06,
	//INT_TM07 (0x48)
	INT_TM07,
	//INT_P6 (0x4A)
	INT_P6,
	//INT_P7 (0x4C)
	INT_P7,
	//INT_P8 (0x4E)
	INT_P8,
	//INT_P9 (0x50)
	INT_P9,
	//INT_P10 (0x52)
	INT_P10,
	//INT_P11 (0x54)
	INT_P11,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_MD (0x5E)
	INT_MD,
	// Padding
	(void*)0xFFFF,
	//INT_FL (0x62)
	INT_FL,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_BRK_I (0x7E)
	INT_BRK_I,
};

