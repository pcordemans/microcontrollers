#include "OST.h"

OneShotTimer::OneShotTimer(uint32_t milliseconds){
	
	NVIC_SetVector(TIMER0_IRQn,(uint32_t)&OneShotTimer::isr); // Register ISR at Timer0 interrupt vector
	NVIC_EnableIRQ(TIMER0_IRQn); //Enable the interrupt vector

	LPC_TIM0->PR = 1000; // prescale with 1000
	LPC_TIM0->MR0 = 24*milliseconds;  // Match count for 1ms * milliseconds
    LPC_TIM0->MCR = 5;     // Interrupt and Stop on Match
    
}

void OneShotTimer::start(void (*func)()) {
	continuation_func = func;
	LPC_TIM0->TCR = 1;     // Enable Timer0
}

void OneShotTimer::isr(OneShotTimer* ost) {
	ost->continuation_func();
	LPC_TIM0->IR |= 1 << 0; // clear the interrupt flag
	assert(LPC_TIM0->IR == 0) ;  // read the interrupt flag to make sure it has been set
}
