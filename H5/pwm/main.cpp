#include "pwm.h"

void approx_wait(uint32_t milliseconds) {
	for (uint32_t j = 0; j < milliseconds; j++) {
		for (volatile uint32_t i = 0; i < 7320; i++);
	}
}

int main(){
  PWM pwm(6, 4000, 25);
  pwm.start();
  pwm.setDutyCycle(50);
  //uint8_t dutyCycle = 0;

  while(true){
    //pwm.setDutyCycle(dutyCycle);
    //(dutyCycle % 100) ? dutyCycle++ : dutyCycle = 0;
    //approx_wait(100);
  }
  return 0;
}
