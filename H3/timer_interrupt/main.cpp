#include "LPC17xx.h"
#include "cmsis_nvic.h" 
#include <assert.h>

extern "C"{ 
	void TIMER0_IRQHandler() {
		LPC_GPIO1->FIOPIN = ~(LPC_GPIO1->FIOPIN); //toggle LED 1	
		LPC_TIM0->IR |= 1 << 0; // clear the interrupt flag
		assert(LPC_TIM0->IR == 0) ; // read the interrupt flag to make sure it has been set
	}
}
 
 
int main() {
	// LED 1 init
	LPC_GPIO1->FIODIR |= (1<<18); //select p1.18 (LED 1) and write 1 to make it an output
	LPC_GPIO1->FIOMASK = ~(1<<18); //mask only the 18th bit when reading or writing to FIOPIN

	
	NVIC_EnableIRQ(TIMER0_IRQn); //Enable the interrupt vector

	LPC_TIM0->MR0 = 3600000;  // Match count for 150ms
    LPC_TIM0->MCR = 3;     // Interrupt and Reset on Match
    LPC_TIM0->TCR = 1;     // Enable Timer0
 
    while (1) {} // wait here for interrupts
}
