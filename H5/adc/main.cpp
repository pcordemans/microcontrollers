#include "mbed.h"

Serial pc(USBTX, USBRX);

uint16_t value = 0xffff;

extern "C"{
  void ADC_IRQHandler(){
      value = (LPC_ADC->ADDR5 & 0xFFF0) >> 4; //read from adc channel 5
      NVIC->ICER[0] |= (1 << 22); //disable ADC interrupt
  }
}

void approx_wait(uint32_t milliseconds) {
	for (uint32_t j = 0; j < milliseconds; j++) {
		for (volatile uint32_t i = 0; i < 7320; i++);
	}
}

void adc_init(){
  LPC_SC->PCONP |= (1 << 12); //power adc: set the PCADC bit
  LPC_ADC->ADCR |= (1 << 21); //enable adc: set the PDN bit
  LPC_ADC->ADCR |= (1 << 8); //PCLK = 24 MHz, CLKDIV = 1+1 = 2 -> ADC clk = 24/2 = 12MHz < 13MHz
  LPC_PINCON->PINSEL3 |= (3 << 30); //Configure pin AD0.5
  LPC_ADC->ADCR |= (1 << 5); //Select AD0.5
  LPC_ADC->ADINTEN &= ~(1 << 8); //Only the individual ADC channels generate interrupts
  LPC_ADC->ADINTEN |= (1 << 5); //interrupt enabled on channel 5
}

void adc_start(){
  NVIC->ISER[0] |= (1 << 22); //enable ADC interrupt
  LPC_ADC->ADCR |= (1 << 24); //start conversion now
  approx_wait(1); //needs to wait, not sure why?
}

int main(){

  adc_init();

  adc_start();

  while(value == 0xffff){}
  pc.printf("%x\r\n",  value);

  while(true){
  }

  return 0;
}
