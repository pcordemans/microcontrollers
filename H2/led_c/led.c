#include "led.h"

static const uint8_t mask_offset = 0x4;
static const uint8_t clr_offset = 0x7;
static const uint8_t set_offset = 0x6;
static const uint8_t pin_offset = 0x5;

void led_init(volatile uint32_t* base_address, uint8_t pin) {
	*(base_address) |= (1 << pin); 
	*(base_address + mask_offset) &= ~(1 << pin);
}

void on(volatile uint32_t* base_address, uint8_t pin) {
	*(base_address + set_offset) |= (1 << pin);
}

void off(volatile uint32_t* base_address, uint8_t pin) {
	*(base_address + clr_offset) |= (1 << pin);
}

void toggle(volatile uint32_t* base_address, uint8_t pin) {
	if(*(base_address + pin_offset) & (1 << pin))
		off(base_address, pin);
	else
		on(base_address, pin);
}