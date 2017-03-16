#include "gpout.h"

volatile uint32_t* GPout::base_address = (volatile uint32_t*)0x2009C000;

GPout::GPout(uint8_t port, uint8_t pin) {
	this->port_base_address = base_address + (port * 0x08);
	this->pin = pin;

	*(port_base_address) |= (1 << pin);
	*(port_base_address + mask_offset) &= ~(1 << pin);
}

void GPout::on() {
	*(port_base_address + set_offset) |= (1 << pin);
}

void GPout::off() {
	*(port_base_address + clr_offset) |= (1 << pin);
}

void GPout::toggle() {
	if(this->read())
		off();
	else
		on();
}

bool GPout::read(){
	return (*(port_base_address + pin_offset) & (1 << pin));
}
