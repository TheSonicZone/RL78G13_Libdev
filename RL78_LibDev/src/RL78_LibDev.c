//------------------------------------------------------------------------------------------------
//
//					The Sonic Zone (PTY) LTD
//				Renesas RL78/G13 Code Library Development
//
//------------------------------------------------------------------------------------------------


// Included headers
#include "../core/iodefine.h"
#include "../core/iodefine_ext.h"
#include "../core/rl78_g13.h"
#include "../core/rl78_clock_sys.h"
#include "../RL78StdPeriphLib/rl78_interval_timer.h"
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
	uint8_t ITIFValue;

	// System Initialisation
	asm("DI");											// Ensure interrupts are disabled
	InitClockSystem(X1_HIGHSPEED, XT1_NORMAL);
	SetCPUClockX1();

	// Peripheral Initialisation
	//--------------------------
	InitIntervalTimer(3000);

	// GPIO Initalisation
	LED01_PIN = 0; // Make Pin as O/P
	LED01 = 0; // Turn LED ON

	// Simple loop to test clocks etc...

	while(1){

		// Flash LED by polling the interrupt flags
		// User manual doesn't say you can do this but you can
		ITIFValue = IF1H;
		if((ITIFValue & 0x04) == 0x04){
			LED01 = ~LED01;
			ITIF = 0;
		}
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

// definition of this function in inthander.c I changed to weak attribute so that it can be overriden
void INT_IT (void){


}

