//
//			Filename: devicetype.h
//
//			Definition of the device type for some parts of the library that need to know
//          which package is being used (from the part number) in order to be able to initialise
//          peripherals correctly
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
#ifndef DEVICETYPE_H_
#define DEVICETYPE_H_


#define R5F100L

typedef enum{
	package_20_pin,
	package_24_pin,
	package_25_pin,
	package_30_pin,
	package_32_pin,
	package_36_pin,
	package_40_pin,
	package_44_pin,
	package_48_pin,
	package_52_pin,
	package_64_pin,
	pakcage_80_pin,
	package_100_pin,
	package_128_pin,

}packages;


#ifdef R5F1006
#define device package_20_pin
#endif

#ifdef R5F1016
#define device package_20_pin

#endif

#ifdef R5F1007
#define device package_24_pin

#endif

#ifdef R5F1017
#define device package_24_pin

#endif


#ifdef R5F1008
#define device package_25_pin

#endif

#ifdef R5F1018
#define device package_25_pin

#endif

#ifdef R5F100A
#define device package_30_pin

#endif

#ifdef R5F101A
#define device package_30_pin

#endif

#ifdef R5F100B
#define device package_32_pin

#endif

#ifdef R5F101B
#define device package_32_pin

#endif


#ifdef R5F100C
#define device package_36_pin

#endif

#ifdef R5F101C
#define device package_36_pin

#endif

#ifdef R5F100E
#define device package_40_pin

#endif

#ifdef R5F101E
#define device package_40_pin

#endif

#ifdef R5F100F
#define device package_44_pin

#endif

#ifdef R5F101F
#define device package_44_pin

#endif

#ifdef R5F100G
#define device package_48_pin

#endif

#ifdef R5F101G
#define device package_48_pin

#endif

#ifdef R5F100J
#define device package_52_pin

#endif

#ifdef R5F101J
#define device package_52_pin

#endif

#ifdef R5F100L
#define device package_64_pin

#endif

#ifdef R5F101L
#define device package_64_pin

#endif

#ifdef R5F100M
#define device package_80_pin

#endif

#ifdef R5F101M
#define device package_80_pin

#endif

#ifdef R5F100P
#define device package_100_pin

#endif

#ifdef R5F101P
#define device package_100_pin

#endif

#ifdef R5F100S
#define device package_128_pin

#endif

#ifdef R5F101S
#define device package_128_pin

#endif


#ifndef device
#error "Device is not defined! Please check device in devicetype.h"
#endif



#endif /* DEVICETYPE_H_ */
