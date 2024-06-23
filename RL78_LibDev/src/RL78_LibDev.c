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
	InitClockSystem(X1_HIGHSPEED, XT1_NORMAL);
	SetCPUClockX1();


	// GPIO Initalisation
	LED01_PIN = 0; // Make Pin as O/P
	LED01 = 0; // Turn LED ON

	// Simple loop to test clocks etc...

	while(1){
		LED01 = ~LED01; // toggle LED
		for(Count = 0; Count < 10000; Count++);{
			asm("nop"); // do nothing
		}

	}
	return 0;
}
