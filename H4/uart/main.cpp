#include "uart.h"

int main(){
  UART pc;

  while(true) {
    char c = pc.getc();
    if (c == 'z') c = 'a';
    else c++;
    pc.putc(c);
  }
}
