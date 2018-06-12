#include "Capture.h"

Capture::Capture(){
  LPC_SC->PCONP |= (1<<23); //power timer 3
  LPC_PINCON->PINSEL1 |= (3<<14); //configure p15 as CAP3.0
  LPC_TIM3->CCR |= 5; //CAP 3.0 trigger rising edge and generate interrupt
}

void Capture::start(){
  LPC_TIM3->TCR |= 2; //timer reset
  LPC_TIM3->TCR |= 1; //start timer
}

uint32_t Capture::read(){
  return LPC_TIM3->CR0;
}
