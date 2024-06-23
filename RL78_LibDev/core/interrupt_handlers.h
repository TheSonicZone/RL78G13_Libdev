//
//			Filename: interrupt_handlers.h
//          Interrupt handler definitions for RL78/G13
//
//			Based on code provided by Renesas Electronics via Appilet
//          (changed for ease of use and logical functionality)
//
//			GNURL78 is an old-school C compiler, and as such, will need this
//          file and the matching inthandler.c because the __interrupt keyword and
//          interrupt pragma do not exist in this variant of GCC.
//			Hence the interrupt declaration pattern used in everything these days from
//          GCC for ARM and MSP430, cannot be used :(
//			It's a shame really
//          but no effort has been put into doing a decent toolchain for this product!
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
#ifndef INTERRUPT_HANDLERS_H
#define INTERRUPT_HANDLERS_H

// Watchdog
void INT_WDTI(void) __attribute__ ((interrupt));

/*
 * INT_LVI (0x6)
 */
void INT_LVI(void) __attribute__ ((interrupt));

/*
 * INT_P0 (0x8)
 */
void INT_P0(void) __attribute__ ((interrupt));

/*
 * INT_P1 (0xA)
 */
void INT_P1(void) __attribute__ ((interrupt));

/*
 * INT_P2 (0xC)
 */
void INT_P2(void) __attribute__ ((interrupt));

/*
 * INT_P3 (0xE)
 */
void INT_P3(void) __attribute__ ((interrupt));

/*
 * INT_P4 (0x10)
 */
void INT_P4(void) __attribute__ ((interrupt));

/*
 * INT_P5 (0x12)
 */
void INT_P5(void) __attribute__ ((interrupt));

/*
 * INT_CSI20/INT_IIC20/INT_ST2 (0x14)
 */
void INT_ST2(void) __attribute__ ((interrupt));
//void INT_CSI20(void) __attribute__ ((interrupt));
//void INT_IIC20(void) __attribute__ ((interrupt));

/*
 * INT_CSI21/INT_IIC21/INT_SR2 (0x16)
 */
void INT_SR2(void) __attribute__ ((interrupt));
//void INT_CSI21(void) __attribute__ ((interrupt));
//void INT_IIC21(void) __attribute__ ((interrupt));

/*
 * INT_SRE2 (0x18)
 */
void INT_SRE2(void) __attribute__ ((interrupt));

// DMA Channel 0
void INT_DMA0(void) __attribute__ ((interrupt));

// DMA Channel 1
void INT_DMA1(void) __attribute__ ((interrupt));

/*
 * INT_CSI00/INT_IIC00/INT_ST0 (0x1E)
 */
void INT_ST0(void) __attribute__ ((interrupt));
//void INT_CSI00(void) __attribute__ ((interrupt));
//void INT_IIC00(void) __attribute__ ((interrupt));

/*
 * INT_CSI01/INT_IIC01/INT_SR0 (0x20)
 */
void INT_SR0(void) __attribute__ ((interrupt));
//void INT_CSI01(void) __attribute__ ((interrupt));
//void INT_IIC01(void) __attribute__ ((interrupt));

/*
 * INT_SRE0/INT_TM01H (0x22)
 */
void INT_TM01H(void) __attribute__ ((interrupt));
//void INT_SRE0(void) __attribute__ ((interrupt));

/*
 * INT_CSI10/INT_IIC10/INT_ST1 (0x24)
 */
void INT_ST1(void) __attribute__ ((interrupt));
//void INT_CSI10(void) __attribute__ ((interrupt));
//void INT_IIC10(void) __attribute__ ((interrupt));

/*
 * INT_CSI11/INT_IIC11/INT_SR1 (0x26)
 */
void INT_SR1(void) __attribute__ ((interrupt));
//void INT_CSI11(void) __attribute__ ((interrupt));
//void INT_IIC11(void) __attribute__ ((interrupt));

/*
 * INT_SRE1/INT_TM03H (0x28)
 */
void INT_TM03H(void) __attribute__ ((interrupt));
//void INT_SRE1(void) __attribute__ ((interrupt));

// I2C Peripheral
void INT_IICA0(void) __attribute__ ((interrupt));

/*
 * INT_TM00 (0x2C)
 */
void INT_TM00(void) __attribute__ ((interrupt));

/*
 * INT_TM01 (0x2E)
 */
void INT_TM01(void) __attribute__ ((interrupt));

/*
 * INT_TM02 (0x30)
 */
void INT_TM02(void) __attribute__ ((interrupt));

// Timer 3
void INT_TM03(void) __attribute__ ((interrupt));

// A/D converter
void INT_AD(void) __attribute__ ((interrupt));

// Real-time clock
void INT_RTC(void) __attribute__ ((interrupt));

// Interval Timer
void INT_IT(void) __attribute__ ((interrupt));

/*
 * INT_KR (0x3A)
 */
void INT_KR(void) __attribute__ ((interrupt));

// Timer 4
void INT_TM04(void) __attribute__ ((interrupt));

// Timer 5
void INT_TM05(void) __attribute__ ((interrupt));

// Timer 6
void INT_TM06(void) __attribute__ ((interrupt));

// Timer 7
void INT_TM07(void) __attribute__ ((interrupt));

// Port 6
void INT_P6(void) __attribute__ ((interrupt));

// Port 7
void INT_P7(void) __attribute__ ((interrupt));

// Port 8
void INT_P8(void) __attribute__ ((interrupt));

/*
 * INT_P9 (0x50)
 */
void INT_P9(void) __attribute__ ((interrupt));

/*
 * INT_P10 (0x52)
 */
void INT_P10(void) __attribute__ ((interrupt));

/*
 * INT_P11 (0x54)
 */
void INT_P11(void) __attribute__ ((interrupt));

/*
 * INT_MD (0x5E)
 */
void INT_MD(void) __attribute__ ((interrupt));

/*
 * INT_FL (0x62)
 */
void INT_FL(void) __attribute__ ((interrupt));

// Breakpoint
void INT_BRK_I(void) __attribute__ ((interrupt));

// Reset Vector
void PowerON_Reset(void) __attribute__ ((interrupt));
#endif
