#ifndef UART_H
#define UART_H

namespace microcontrollers{
/**
* UART class for communicating with a UART periperhal on the LPC1768
*/
class UART{
public:
  /**
    * Constructor for the UART with a baudrate of 9600
    */
  UART();
  /**
    * Destructor for the UART
    */
  ~UART();

  /**
    * Puts a character on the UART
    * @param c the character to transmit
    */
  void putc(char c);

  /**
    * Gets a character from the UART
    * @return the character received
    */
  char getc();
};
}
#endif
