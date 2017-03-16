#include "gpin.h"

volatile uint32_t* GPin::port_base_address = (volatile uint32_t*)0x2009C000;
volatile uint32_t* GPin::pinsel_base_address = (volatile uint32_t*)0x4002C000;
volatile uint32_t* GPin::pinmode_base_address = (volatile uint32_t*)0x4002C040;

GPin::GPin(uint8_t port, uint8_t pin, GPpinMode mode){
  this->port_address = port_base_address + (port * 8);
  this->pinsel_address = pinsel_base_address + (port * 2) + ((pin & 0x10) >> 4);
  this->pinmode_address = pinmode_base_address + (port * 2) + ((pin & 0x10) >> 4);
  this->pin = pin;
  this->port = port;

  *(pinsel_address) &= ~(3 << ((pin & 0xF) << 1));

  switch(mode){
    case PULLUP:
      *(pinmode_address) &= ~(3 << ((pin & 0xF) << 1));
      break;
    case REPEATER:
      *(pinmode_address) &= ~(1 << (((pin & 0xF) << 1) + 1));
      *(pinmode_address) |= (1 << ((pin & 0xF) << 1) );
      break;
    case PULLNONE:
      *(pinmode_address) &= ~(1 << ((pin & 0xF) << 1));
      *(pinmode_address) |= (1 << (((pin & 0xF) << 1) + 1));
      break;
    case PULLDOWN: *(pinmode_address) |= (3 << ((pin & 0xF) << 1));
      break;
  }

  *(port_address) &= ~(1 << pin);
	*(port_address + mask_offset) &= ~(1 << pin);
}

bool GPin::read(){
  return (*(port_address + pin_offset) & (1 << pin));
}
