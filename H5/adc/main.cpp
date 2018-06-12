#include "adc.h"
#include "mbed.h"
Serial pc(USBTX, USBRX);
ADC adc;

int main(){

  adc.start();

  pc.printf("%x\r\n", adc.read());

  while(true){
  }

  return 0;
}
