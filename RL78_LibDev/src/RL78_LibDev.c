//------------------------------------------------------------------------------------------------
//
//					The Sonic Zone (PTY) LTD
//				Renesas RL78/G13 Code Library Development
//
//------------------------------------------------------------------------------------------------


// Included headers
#include <stdbool.h>
#include "../core/iodefine.h"
#include "../core/iodefine_ext.h"
#include "../core/rl78_g13.h"
#include "../core/rl78_clock_sys.h"
#include "../RL78StdPeriphLib/rl78_interval_timer.h"
#include "../RL78StdPeriphLib/rl78_serial_array_unit.h"
#include "../core/interrupt_handlers.h"

// Variables
unsigned long Count;

// Constants

// Definitions
#define LED01_PIN   PM4_bit.no3
#define LED01       P4_bit.no3

//------------------------------------------------------------------------------------------------
// Main Function
//------------------------------------------------------------------------------------------------
int main(void){


	// System Initialisation
	//----------------------
	asm("DI");											// Ensure interrupts are disabled
	InitClockSystem(X1_HIGHSPEED, XT1_NORMAL);
	SetCPUClockX1();

	// Peripheral Initialisation
	//--------------------------
	InitIntervalTimer(3000);				// Interval timer is set

	sau_config_struct UARTConfig;

	UARTConfig.baudrate = baud_9600;
	UARTConfig.mode = UART_Mode;
	UARTConfig.parity = no_parity;
	UARTConfig.prescale_ck00 = 0x03;
	UARTConfig.prescale_ck01 = 0x03;
	UARTConfig.rx_interrupt_enable = false;
	UARTConfig.tx_interrupt_enable = false;
	UARTConfig.stop_bits = stopbits_1;
	UARTConfig.transfer_length = transfer_8bits;
	UARTConfig.error_irq_setting = error_interrupt_disabled;
	ConfigSerialArray(0, &UARTConfig);

	// GPIO Initalisation
	LED01_PIN = 0; // Make Pin as O/P
	LED01 = 0; // Turn LED ON

	// Globally enable interrupts
	asm("EI");

	// Simple loop to test clocks etc...

	while(1){

		// Flash LED by polling the interrupt flags
		// User manual doesn't say you can do this but you can
		//ITIFValue = IF1H;
		//if((ITIFValue & 0x04) == 0x04){
		//	LED01 = ~LED01;
			//ITIF = 0;
		//}
//		LED01 = ~LED01; // toggle LED
//		for(Count = 0; Count < 10000; Count++);{
//			asm("nop"); // do nothing
//		}

	}
	return 0;
}


//----------------------------------------------------------------------------------------------------
// Interrupt Handlers
//----------------------------------------------------------------------------------------------------

// definition of this function in inthander.c I changed to weak attribute so that it can be overridden


// INT_IT interrupt - Interval timer
void INT_IT (void){
	LED01 = ~LED01;
	putUARTChar('A');

}

