#ifndef LED_H
#define LED_H
#include <stdint.h>

	/**
	  * Sets pin direction to output
	  * @param base_address port base address (FIODIR)
	  * @param pin number
	  */
	void led_init(volatile uint32_t* base_address, uint8_t pin);
	/**
	  * Turn the led on
	  * @param base_address port base address (FIODIR)
	  * @param pin number
	  */
	void on(volatile uint32_t* base_address, uint8_t pin);
	/**
	  * Turn the led off
	  * @param base_address port base address (FIODIR)
	  * @param pin number
	  */
	void off(volatile uint32_t* base_address, uint8_t pin);
	/**
	  * Toggle the led
	  * @param base_address port base address (FIODIR)
	  * @param pin number
	  */
	void toggle(volatile uint32_t* base_address, uint8_t pin);

#endif