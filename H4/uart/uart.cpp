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

  //3. Disable DLAB (bit 7) in U0LCR
  LPC_UART0->LCR &= ~(1 << 7);

  //4. Enable FIFOs
  LPC_UART0->FCR |= 1;
  //5. Select TXD0 and RXD0 as pin function
  LPC_PINCON->PINSEL0 |= 0x50;
  LPC_PINCON->PINMODE0 |= 0xA0;

  //8. Enable 8N1
  LPC_UART0->LCR |= 3;

}

UART::~UART(){

}

void UART::putc(char c){
  while((LPC_UART0->LSR & 0x20) == 0);
  LPC_UART0->THR  = c;
}

char UART::getc(){
  while((LPC_UART0->LSR & 1) == 0);
  return LPC_UART0->RBR;
}
