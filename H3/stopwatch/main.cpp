#include "Capture.h"
#include "mbed.h"
#include <assert.h>

bool captureComplete = false;

extern "C"{
	void TIMER3_IRQHandler() {
		captureComplete = true;
		LPC_TIM3->IR |= 1 << 0; // clear the interrupt flag
		assert(LPC_TIM3->IR == 0) ; // read the interrupt flag to make sure it has been set
	}
}

DigitalIn down(p12);
Capture capture;
Serial pc(USBTX, USBRX);


int main() {
	pc.printf("Wait till down");
	while(!down.read());
	capture.start();
	pc.printf("Capture started");
	while (!captureComplete);
	pc.printf("Elapsed time %d", capture.read());
}
