#include <stdint.h> //include for uint32_t definitions
#include "led.h"
/**
  * keeps the processor busy approximately for a given time
  * @param milliseconds to keep the processor busy
  */
void approx_wait(uint32_t milliseconds) {
	for (uint32_t j = 0; j < milliseconds; j++) {
		for (volatile uint32_t i = 0; i < 7320; i++);
	}
}

int main() {

	volatile uint32_t* base = (volatile uint32_t*) (0x2009C020);
	uint8_t pin = 18;
	led_init(base, pin);

	while (1) {
		toggle(base, pin);
		approx_wait(1000);
	}
}
