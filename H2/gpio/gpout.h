#ifndef GPOUT_H
#define GPOUT_H
#include <stdint.h>

/**
  * Single IO pin
	*/
class GPout {
public:
	/**
	  * Select port and pin 
		* @param port 0 - 4
		* @param pin 0 - 31
	  */
	GPout(uint8_t port, uint8_t pin);
	/**
	  * Brings the pin to a high state
	  */
	void on();
	/**
	  * Brings the pin to a low state
	  */
	void off();
	/**
	  * Toggles the pin state
	  */
	void toggle();

	/**
	  * @return the state on the pin true if high, false otherwise
		*/
	bool read();

private:

	uint8_t port;
	uint8_t pin;

	volatile uint32_t* port_address;
	volatile uint32_t* pinsel_address;

	static volatile uint32_t* pinsel_base_address;
	static volatile uint32_t* port_base_address;
	static const uint8_t mask_offset = 0x4;
	static const uint8_t clr_offset = 0x7;
	static const uint8_t set_offset = 0x6;
	static const uint8_t pin_offset = 0x5;
};

#endif
