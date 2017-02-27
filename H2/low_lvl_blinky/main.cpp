#include <LPC17xx.h> //needed for LPC_GPIO & FIO definitions

/**
  * keeps the processor busy approximately for a given time
  * @param milliseconds to keep the processor busy
  */
void approx_wait(uint32_t milliseconds) {
	for (uint32_t j = 0; j < milliseconds; j++) {
		for (volatile uint32_t i = 0; i < 7320; i++);
	}
}

/**
  * Selects the direction of the pin p1.18
  * & applies a hardware mask
  */
void init() {
	LPC_GPIO1->FIODIR |= (1 << 18); //select p1.18 (LED 1) and write 1 to make it an output
	LPC_GPIO1->FIOMASK &= ~(1 << 18); //only select p1.18
}

/**
  * Blinks LED1 (located at p1.18) at a period of 400ms
  */
void blink() {
	LPC_GPIO1->FIOCLR |= (1 << 18); //select p1.18 and write 0 to turn it off
	approx_wait(200);
	LPC_GPIO1->FIOSET |= (1 << 18); //select p1.18 and write 1 to turn it on
	approx_wait(200);
}

int main() {
	init();
	while (true) {
		blink();
	}
}
