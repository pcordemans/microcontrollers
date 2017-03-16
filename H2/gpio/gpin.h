#ifndef GPIN_H
#define GPIN_H
#include <stdint.h>
enum GPpinMode{PULLUP, REPEATER, PULLNONE, PULLDOWN};

class GPin {
public:
	/**
	  * Select port, pin and mode
		* @param port 0 - 4
		* @param pin 0 - 31
		* @param mode PULLUP, REPEATER, PULLNONE, PULLDOWN
	  */
	GPin(uint8_t port, uint8_t pin, GPpinMode mode);

  /**
	  * @return the state on the pin true if high, false otherwise
		*/
	bool read();

private:
  uint8_t port;
  uint8_t pin;

  volatile uint32_t* port_address;
	volatile uint32_t* pinsel_address;
  volatile uint32_t* pinmode_address;

	static volatile uint32_t* pinsel_base_address;
	static volatile uint32_t* port_base_address;
  static volatile uint32_t* pinmode_base_address;

  static const uint8_t mask_offset = 0x4;
  static const uint8_t pin_offset = 0x5;
};

#endif
