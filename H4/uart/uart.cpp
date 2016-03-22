#include "uart.h"
#include "LPC17xx.h"

UART::UART(){

  //1. On reset Power is enabled
  //2. PCLK for UART0 CCLK/4 = 24MHZ
  //3. Enable DLAB (bit 7) in U0LCR
  LPC_UART0->LCR |= (1 << 7);
  LPC_UART0->DLL = 0x68; //And: DLM = 0, DLL = 0x68
  LPC_UART0->DLM = 0;
  LPC_UART0->FDR = 0x21; // DIVADDVAL = 1 & MULVAL = 2

  //3. Disbal DLAB (bit 7) in U0LCR
  LPC_UART0->LCR &= ~(1 << 7);
}

UART::~UART(){

}

void UART::putc(char c){

}

char UART::getc(){
  return 0;
}
