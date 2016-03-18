#ifndef OST_H
#define OST_H

#include "LPC17xx.h"
#include "cmsis_nvic.h" 
#include <assert.h>

class OneShotTimer {
public:
	OneShotTimer(uint32_t milliseconds);
	void start(void (*func)());

private:
	static void isr(OneShotTimer* ost);
	void (*continuation_func)();

}; 

#endif