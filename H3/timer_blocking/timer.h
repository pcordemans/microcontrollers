#ifndef TIMER_H
#define TIMER_H

#include "stdint.h"
#include "LPC17xx.h"

class Timer{
public:
  static void wait(uint32_t microseconds);
private:
  static bool initialised;
  static void init();
};

#endif
