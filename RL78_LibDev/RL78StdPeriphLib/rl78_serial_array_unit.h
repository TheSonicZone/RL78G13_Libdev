//-----------------------------------------------------------------------------------------
//
//					Header file for SAU Driver
//					RL78_serial_array_unit.h
//-----------------------------------------------------------------------------------------

#include <inttypes.h>
#ifndef RL78_SERIAL_ARRAY_UNIT_H_
#define RL78_SERIAL_ARRAY_UNIT_H_

// Definitions
//------------



#define CSI_Mode 		0x00     // 3 wire serial aka SPI sans CS
#define UART_Mode 		0x01     // Regular UART
#define SimpleI2C_Mode 	0x02     // Simplified I2C

// Enumerated type for all possible baudrates
enum baudrates{

	baud_9600,
	baud_19200,
	baud_38400,
	baud_57600,
	baud_115200
};

typedef struct{
	uint8_t prescale_ck00;
	uint8_t prescale_ck01;
	uint8_t mode;
	uint8_t baudrate;
	uint16_t parity;
	uint8_t tx_interrupt_enable;
	uint8_t rx_interrupt_enable;
	uint16_t stop_bits;
	uint16_t transfer_length;
	uint16_t error_irq_setting;

}sau_config_struct;

enum parity{
	no_parity = parity_none,
	odd_parity = parity_odd,
	even_parity = parity_even,
	zero_parity = parity_zero
};

enum stop_bits{
	stopbits_1 = one_stop_bits,
	stopbits_2 = two_stop_bits,
	nostopbits = no_stop_bits
};

enum xferlen{
	transfer_8bits = bit_xfr_8_bits,
	transfer_9bits = bit_xfr_9_bits,
	transfer_7bits = bit_xfr_7_bits
};

enum error_irqs{
	error_interrupt_enabled = EOCmn,
	error_interrupt_disabled = 0x0000
};

// baudrate constants at 20MHz system clock
//-----------------------------------------
#define baud_const_9600 0xF700

// Function Prototypes
//---------------------
int InitSAU0(uint8_t divide_m0, uint8_t divide_m1);
int InitSAU1(uint8_t divide_m0, uint8_t divide_m1);
int ConfigSAU0(uint8_t mode_p1, uint8_t mode_p2);
int ConfigSerialArray(uint8_t unit, sau_config_struct *config);

void putUARTChar(unsigned char c);


#endif /* RL78_SERIAL_ARRAY_UNIT_H_ */
