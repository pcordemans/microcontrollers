#ifndef PWM_H
#define PWM_H

#include "LPC17xx.h"

/**
* PWM1 on the LPC1768
*/
class PWM{
public:
  /**
    * Timer-based PWM: no interrupts, single edge control
    *
    * @param pin 1 - 6 (p2.0/PWM1.1 - p2.5/PWM1.6)
    * @param frequency 1 - 2400000(Hz)
    */
  PWM(uint8_t pin, uint32_t frequency, uint8_t dutyCycle);
  /**
    * Destructor
    */
  ~PWM();

  /**
    * Starts PWM generation
    */
  void start();

  /**
    * Stops PWM generation
    */
  void stop();

  /**
    * Sets the duty cycle
    *
    * @param dutyCycle 0 - 100
    */
  void setDutyCycle(uint8_t dutyCycle);

private:
  uint8_t pwm_pin;
  uint32_t pwm_frequency;
  static const uint32_t pclk = 24000000;
  volatile uint32_t* match;
};

#endif
