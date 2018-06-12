#include "adc.h"

ADC::ADC(){
  LPC_SC->PCONP |= (1 << 12); //power adc: set the PCADC bit
  LPC_ADC->ADCR |= (1 << 21); //enable adc: set the PDN bit
  LPC_ADC->ADCR |= (1 << 8); //PCLK = 24 MHz, CLKDIV = 1+1 = 2 -> ADC clk = 24/2 = 12MHz < 13MHz
  LPC_PINCON->PINSEL3 |= (3 << 30); //Configure pin AD0.5
  LPC_ADC->ADCR |= (1 << 5); //Select AD0.5
  //NVIC->ISER[0] |= (1 << 22); //enable ADC interrupt
}

ADC::~ADC(){

}

void ADC::start(){
  //LPC_ADC->ADINTEN |= (1 << 5); //interrupt enabled on channel 5
  LPC_ADC->ADCR |= (1 << 24); //start conversion now
}

uint16_t ADC::read(){
  //LPC_ADC->ADINTEN &= ~(1 << 5); //disable interrupt
  while(!(LPC_ADC->ADDR5 & (1<<31))){}
  return (LPC_ADC->ADDR5 & 0xFFF0) >> 4;
}
