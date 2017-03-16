#include <stdint.h> 
#include "gpout.h"
#include "gpin.h"

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

	GPout led1(1, 18);
	GPout led2(1, 20);
	GPout led3(1, 21);
	GPout led4(1, 23);

	GPin center(0, 16, PULLDOWN);
	GPin up(0, 23, PULLDOWN);
	GPin down(0, 17, PULLDOWN);
	GPin left(0, 15, PULLDOWN);
	GPin right(0, 24, PULLDOWN);

	while (true) {
		if(up.read()){
			led1.toggle();
			approx_wait(500);
		}
		if(down.read()){
			led2.toggle();
			approx_wait(500);
		}
		if(left.read()){
			led3.toggle();
			approx_wait(500);
		}
		if(right.read()){
			led4.toggle();
			approx_wait(500);
		}
	}
}
