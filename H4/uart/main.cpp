#include "uart.h"
#include <stdint.h> //include for uint32_t definitions
using namespace microcontrollers;


int main(){
  UART pc;
  while(true){
    pc.putc(pc.getc());
  }
  return 0;
}
