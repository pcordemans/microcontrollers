#include "uart.h"
#include "LPC17xx.h"
using namespace microcontrollers;

UART::UART(){

  //1. On reset Power is enabled
  //2. PCLK for UART0 CCLK/4 = 24MHZ
  //3. Enable DLAB (bit 7) in U0LCR
  LPC_UART0->LCR |= (1 << 7);
  LPC_UART0->DLL = 0x68; //DLM = 0, DLL = 0x68
  LPC_UART0->DLM = 0;
  LPC_UART0->FDR = 0x21; // DIVADDVAL = 1 & MULVAL = 2

  //4. Enable FIFO bit
  LPC_UART0->FCR |= 7;

  //5. PINSEL0 7:6 01 = TXD0 & 5:4 01 = RXD0
  LPC_PINCON->PINSEL0 |= 0x50;
  //5. PINMODE Rx no pull-up or down configured
  LPC_PINCON->PINMODE0 |= 8;

  //3. Disable DLAB (bit 7) in U0LCR
  LPC_UART0->LCR &= ~(1 << 7);

  //Select 8N1 Mode
  LPC_UART0-> LCR |= 3;
}

UART::~UART(){

}

void UART::putc(char c){
  while((LPC_UART0->LSR & (1 << 5)) == 0); //THR is not empty
  LPC_UART0->THR = c;
}

char UART::getc(){
  while((LPC_UART0->LSR & 1) == 0); //RBR still empty
  return LPC_UART0->RBR;
}
