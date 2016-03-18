#include "OST.h"
 
void continuation() {
	LPC_GPIO1->FIODIR |= (1<<18); //select p1.18 (LED 1) and write 1 to make it an output
	LPC_GPIO1->FIOPIN |= (1 << 18); //set LED 1	
	
}
  
int main() {
	// LED 1 init
	OneShotTimer ost(5000);
	ost.start(&continuation);
 
    while (1) {} // wait here for interrupts
}
