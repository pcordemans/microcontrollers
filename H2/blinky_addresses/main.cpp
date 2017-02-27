#include <stdint.h> //include for uint32_t definitions

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
	auto direction = (volatile uint32_t *) (0x2009C020);
	auto mask =  (volatile uint32_t *) (0x2009C030);
	*direction |= (1 << 18); //select p1.18 (LED 1) and write 1 to make it an output
	*mask &= ~(1 << 18); //only select p1.18
}

/**
  * Blinks LED1 (located at p1.18) at a period of 400ms
  */
void blink() {
	auto clr = (volatile uint32_t *) (0x2009C03C);
	*clr |= (1 << 18); //select p1.18 and write 0 to turn it off
	approx_wait(500);

	auto set = (volatile uint32_t *) (0x2009C038);
	*set |= (1 << 18); //select p1.18 and write 1 to turn it on
	approx_wait(500);
}

int main() {
	init();
	while (true) {
		blink();
	}
}
