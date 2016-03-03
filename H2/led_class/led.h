#ifndef LED_H
#define LED_H
#include <stdint.h>

class Led {
public:
	/**
	  * Sets pin direction to output
	  */
	Led(volatile uint32_t* port_base_address, uint8_t pin);
	/**
	  * Turn the led on
	  */
	void on();
	/**
	  * Turn the led off
	  */
	void off();
	/**
	  * Toggle the led
	  */
	void toggle();

private:
	volatile uint32_t* port_base_address;
	uint8_t pin;
	static const uint8_t mask_offset = 0x4;
	static const uint8_t clr_offset = 0x7;
	static const uint8_t set_offset = 0x6;
	static const uint8_t pin_offset = 0x5;
};

#endif