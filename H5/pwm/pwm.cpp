#include "pwm.h"

PWM::PWM(uint8_t pin, uint32_t frequency, uint8_t dutyCycle){
  pwm_pin = pin;
  pwm_frequency = frequency;
  //1/ PCONP register, set bit PCPWM1. Remark: On reset, the PWM is enabled (PCPWM1 = 1).
  //2/ Peripheral clock: In the PCLKSEL0 register, select PCLK_PWM1. Default CCLK/4: (24MHz)
  //3/ Pins: Select PWM pins through the PINSEL registers. Select pin modes for port pins with PWM1 functions through the PINMODE registers
  LPC_PINCON->PINSEL4 |= (1 << ((pin - 1)*2));
  LPC_PINCON->PINSEL4 &= ~(1 << (((pin - 1)*2)+1));

  //4/ Count control: Timer mode (enabled at reset)
  //5/ PWM control: enable PWMpin output
  LPC_PWM1->PCR |= (1 << (8 + pin));

  //6/ Match control: reset on match0, IMPORTANT DO NOT CONFIGURE OTHER MATCH REGISTERS
  LPC_PWM1->MCR |= 2;

  //7/ Timer match0 register: PWM frequency
  LPC_PWM1->MR0 = 24000000 / frequency;

  //8/ Timer matchx register: duty cycle
  auto match = (volatile uint32_t*)0x40018048;
  *match = (24000000 * dutyCycle) / (pwm_frequency * 100);

  //9/ Timer Control register: PWM mode enabled
  LPC_PWM1->TCR = (1 << 3);
}

PWM::~PWM(){

}

void PWM::start(){
  //enable counting
  LPC_PWM1->TCR |= 1;
}

void PWM::stop(){
  //stop counting
  LPC_PWM1->TCR &= ~1;
  //reset counter
  LPC_PWM1->TCR |= 2;
  LPC_PWM1->TCR &= ~2;
}

void PWM::setDutyCycle(uint8_t dutyCycle){
  //new match value
  *((volatile uint32_t*)(0x40018018 + pwm_pin * 4)) = (24000000 * dutyCycle) / (pwm_frequency * 100);
  //latch enable
  LPC_PWM1->LER |= (1 << pwm_pin);
}
