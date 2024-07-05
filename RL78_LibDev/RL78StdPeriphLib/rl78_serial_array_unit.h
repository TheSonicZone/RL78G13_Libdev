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
void InitSAU0(uint16_t clock);
void InitSAU1(uint16_t clock);
void InitSAU0_Channel0(uint8_t mode);

#endif /* RL78_SERIAL_ARRAY_UNIT_H_ */
