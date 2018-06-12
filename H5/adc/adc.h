#ifndef ADC_H
#define ADC_H

#include "LPC17xx.h"

/**
* ADC on the LPC1768
*/
class ADC{
public:
  /**
    * ADC conversion at 12 MHz on channel 5, interrupt notifies when conversion is ready and the value can be read
    */
  ADC();
  /**
    * Destructor
    */
  ~ADC();

  /**
    * Starts ADC conversion
    */
  void start();

  /**
    * Stops PWM generation
    */
  uint16_t read();

private:

};

#endif
