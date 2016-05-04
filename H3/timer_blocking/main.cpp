
#include "timer.h"


int main() {
	// LED 1 init
	LPC_GPIO1->FIODIR |= (1<<18); //select p1.18 (LED 1) and write 1 to make it an output
	LPC_GPIO1->FIOMASK = ~(1<<18); //mask only the 18th bit when reading or writing to FIOPIN


    while (1) {
			timer::wait(1000000);
			LPC_GPIO1->FIOPIN = ~(LPC_GPIO1->FIOPIN); //toggle LED 1
			timer::wait(500000);
			LPC_GPIO1->FIOPIN = ~(LPC_GPIO1->FIOPIN); //toggle LED 1
		}
}
