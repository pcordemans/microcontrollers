#include "led.h"

Led::Led(volatile uint32_t* port_base_address, uint8_t pin) {
	this->port_base_address = port_base_address;
	this->pin = pin;

	*(port_base_address) |= (1 << pin); 
	*(port_base_address + mask_offset) &= ~(1 << pin);
}

void Led::on() {
	*(port_base_address + set_offset) |= (1 << pin);
}

void Led::off() {
	*(port_base_address + clr_offset) |= (1 << pin);
}

void Led::toggle() {
	if(*(port_base_address + pin_offset) & (1 << pin))
		off();
	else
		on();
}