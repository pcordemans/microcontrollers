#ifndef CAPTURE_H
#define CAPTURE_H

#include "LPC17xx.h"

class Capture{
public:
  Capture();
  void start();
  uint32_t read();
};

#endif
