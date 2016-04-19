#include "timer.h"

bool Timer::initialised = false;

void Timer::wait(uint32_t microseconds){
  if (initialised == false) init();
  LPC_TIM0->MR0 = 24 * microseconds;  // Match count for 1µs * microseconds
  LPC_TIM0->TCR = 1;     // Enable Timer0
  while(LPC_TIM0->TCR == 1);
}

void Timer::init(){
    LPC_TIM0->MCR = 6;     // Reset and Stop on Match
}
