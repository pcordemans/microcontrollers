#ifndef TIMER_H
#define TIMER_H

#include "stdint.h"
#include "LPC17xx.h"

namespace timer{
/**
  * Waits for a given number of microseconds (blocking)
  * @param microseconds to wait
  */
 void wait(uint32_t microseconds);

};

#endif
