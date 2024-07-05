//-----------------------------------------------------------------------------------------
//
//					Header file for SAU Driver
//					RL78_serial_array_unit.h
//-----------------------------------------------------------------------------------------

#ifndef RL78_SERIAL_ARRAY_UNIT_H_
#define RL78_SERIAL_ARRAY_UNIT_H_

// Definitions
//------------



#define CSI_Mode 		0x00     // 3 wire serial aka SPI sans CS
#define UART_Mode 		0x01     // Regular UART
#define SimpleI2C_Mode 	0x02     // Simplified I2C


// Function Prototypes
//---------------------
int InitSAU0(uint8_t divide_m0, uint8_t divide_m1);
int InitSAU1(uint8_t divide_m0, uint8_t divide_m1);
int ConfigSAU0(uint8_t mode_p1, uint8_t mode_p2);
#endif /* RL78_SERIAL_ARRAY_UNIT_H_ */
