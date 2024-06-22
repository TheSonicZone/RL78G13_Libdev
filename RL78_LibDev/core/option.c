//------------------------------------------------------------------------------------------
//
//
//               Filename: option.c
//               Option Byte settings for Renesas RL78/G13 Microcontrollers
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
//------------------------------------------------------------------------------------------

// Included headers
//------------------
#include "rl78_g13.h"


// OPTION Bytes
//---------------
const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
		WDTOFF, LVDOFF, HIGHSPEED_INT_1MHZ, DEBUGGING_ENABLED

	//0xef, 0xff, 0xe8, 0x85

};

// Security Bytes
//-----------------
const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


