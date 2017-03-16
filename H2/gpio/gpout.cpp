#include "gpout.h"

volatile uint32_t* GPout::port_base_address = (volatile uint32_t*)0x2009C000;
volatile uint32_t* GPout::pinsel_base_address = (volatile uint32_t*)0x4002C000;

GPout::GPout(uint8_t port, uint8_t pin) {
	this->port_address = port_base_address + (port * 8);
	this->pinsel_address = pinsel_base_address + (port * 2) + ((pin & 0x10) >> 4);
	this->pin = pin;

	*(pinsel_address) &= ~(3 << ((pin & 0xF) << 1));
	*(port_address) |= (1 << pin);
	*(port_address + mask_offset) &= ~(1 << pin);
}

void GPout::on() {
	*(port_address + set_offset) |= (1 << pin);
}

void GPout::off() {
	*(port_address + clr_offset) |= (1 << pin);
}

void GPout::toggle() {
	if(this->read())
		off();
	else
		on();
}

bool GPout::read(){
	return (*(port_address + pin_offset) & (1 << pin));
}
