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

	auto base = (volatile uint32_t *) (0x2009C020);
	Led led1(base, 18);

	while (1) {
		led1.toggle();
		approx_wait(500);
	}
}
