#define F_CPU 16000000UL
#include "avr/io.h"
#include "util/delay.h"

// Input PD2
// Output PB5

int main(void) {
  DDRD &= ~(1 << PD2); // set input mode to arduino pin 2
  DDRB |= (1 << PB5); // set output mode to arduino pin 13
  PORTD |= (1 << PD2); // Enable pull-up resistor, PD2 is HIGH by default -> button unpressed

  while (1) {
    if (!(PIND & (1 << PD2))) { // button pressed
      PORTB &= ~(1 << PB5); // turn on
    } else {
      PORTB |= (1 << PB5); // turn off
    }
  }

  return 0;
}
