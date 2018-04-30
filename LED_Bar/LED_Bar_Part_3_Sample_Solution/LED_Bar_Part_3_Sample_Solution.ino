/*
 * Turn the last project into a library
 * 
 * The pin array and setPin function should be private
 * 
 * The constructor and displayNumber should be public 
 * 
 * In loop, use the nextInt() function from the Calculator problems to take
 *   user input and set the corresponding number of LEDs high.
 * 
 * Within the class, use "this->setPin()" etc. to call functions of the class
 * 
 */

// Include the library
#include "LED_Bar.h"

// LED_Bar object
LED_Bar LEDs(9, 10, 11, 12, 13);

void setup()
{
  // Set up Serial
  Serial.begin(9600);
  delay(50);
}

void loop() 
{
  // Get user input
  int i = nextInt();

  // Call the displayNumber function on the LEDs object
  LEDs.displayNumber(i);
}

// NextInt from the calculator program
int nextInt()
{
  // Wait until there is Serial data
  while (!Serial.available())
    ;
  
  // Then get and return the integer
  return Serial.parseInt();
}

