//
//			Filename: inthandler.c
//          Interrupt handler definitions for RL78/G13
//
//			Based on code provided by Renesas Electronics via Appilet
//          (changed for ease of use and logical functionality)
//			Interrupt handlers defined with weak attribute to allow the user to
//          override them and define his/her own interrupt handlers anywhere
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

/*
 * INT_WDTI (0x4)
 */
void INT_WDTI (void) { }

/*
 * INT_LVI (0x6)
 */
void INT_LVI (void) { }

/*
 * INT_P0 (0x8)
 */
void INT_P0 (void) { }

/*
 * INT_P1 (0xA)
 */
void INT_P1 (void) { }

/*
 * INT_P2 (0xC)
 */
void INT_P2 (void) { }

/*
 * INT_P3 (0xE)
 */
void INT_P3 (void) { }

/*
 * INT_P4 (0x10)
 */
void INT_P4 (void) { }

/*
 * INT_P5 (0x12)
 */
void INT_P5 (void) { }

/*
 * INT_CSI20/INT_IIC20/INT_ST2 (0x14)
 */
void INT_ST2 (void) { }
//void INT_CSI20 (void) { }
//void INT_IIC20 (void) { }

/*
 * INT_CSI21/INT_IIC21/INT_SR2 (0x16)
 */
void INT_SR2 (void) { }
//void INT_CSI21 (void) { }
//void INT_IIC21 (void) { }

/*
 * INT_SRE2 (0x18)
 */
void INT_SRE2 (void) { }

/*
 * INT_DMA0 (0x1A)
 */
void INT_DMA0 (void) { }

/*
 * INT_DMA1 (0x1C)
 */
void INT_DMA1 (void) { }

/*
 * INT_CSI00/INT_IIC00/INT_ST0 (0x1E)
 */
void INT_ST0 (void) { }
//void INT_CSI00 (void) { }
//void INT_IIC00 (void) { }

/*
 * INT_CSI01/INT_IIC01/INT_SR0 (0x20)
 */
void INT_SR0 (void) { }
//void INT_CSI01 (void) { }
//void INT_IIC01 (void) { }

/*
 * INT_SRE0/INT_TM01H (0x22)
 */
void INT_TM01H (void) { }
//void INT_SRE0 (void) { }

/*
 * INT_CSI10/INT_IIC10/INT_ST1 (0x24)
 */
void INT_ST1 (void) { }
//void INT_CSI10 (void) { }
//void INT_IIC10 (void) { }

/*
 * INT_CSI11/INT_IIC11/INT_SR1 (0x26)
 */
void INT_SR1 (void) { }
//void INT_CSI11 (void) { }
//void INT_IIC11 (void) { }

/*
 * INT_SRE1/INT_TM03H (0x28)
 */
void INT_TM03H (void) { }
//void INT_SRE1 (void) { }

/*
 * INT_IICA0 (0x2A)
 */
void INT_IICA0 (void) { }

/*
 * INT_TM00 (0x2C)
 */
void INT_TM00 (void) { }

/*
 * INT_TM01 (0x2E)
 */
void INT_TM01 (void) { }

/*
 * INT_TM02 (0x30)
 */
void INT_TM02 (void) { }

/*
 * INT_TM03 (0x32)
 */
void INT_TM03 (void) { }

/*
 * INT_AD (0x34)
 */
void INT_AD (void) { }

/*
 * INT_RTC (0x36)
 */
void INT_RTC (void) { }

/*
 * INT_IT (0x38)
 */
__attribute__((weak)) void INT_IT (void) { }

/*
 * INT_KR (0x3A)
 */
void INT_KR (void) { }

/*
 * INT_TM04 (0x42)
 */
void INT_TM04 (void) { }

/*
 * INT_TM05 (0x44)
 */
void INT_TM05 (void) { }

/*
 * INT_TM06 (0x46)
 */
void INT_TM06 (void) { }

/*
 * INT_TM07 (0x48)
 */
void INT_TM07 (void) { }

/*
 * INT_P6 (0x4A)
 */
void INT_P6 (void) { }

/*
 * INT_P7 (0x4C)
 */
void INT_P7 (void) { }

/*
 * INT_P8 (0x4E)
 */
void INT_P8 (void) { }

/*
 * INT_P9 (0x50)
 */
void INT_P9 (void) { }

/*
 * INT_P10 (0x52)
 */
void INT_P10 (void) { }

/*
 * INT_P11 (0x54)
 */
void INT_P11 (void) { }

/*
 * INT_MD (0x5E)
 */
void INT_MD (void) { }

/*
 * INT_FL (0x62)
 */
void INT_FL (void) { }

/*
 * INT_BRK_I (0x7E)
 */
void INT_BRK_I (void) { }
