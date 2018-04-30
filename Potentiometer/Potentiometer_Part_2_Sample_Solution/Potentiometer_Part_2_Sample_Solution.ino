/*
 * In this project we again turn our code into a simple library
 * 
 * Look up writing libraries, or look back at the Calculator 
 *   library to set up the required file layout.  
 *   
 * In the upper right of the IDE, below the magnifying glass, 
 *   click the dropdown arrow, then click the New Tab button.
 * 
 * Name the new files 'Potentiometer.h' and 'Potentiometer.cpp'.
 * 
 * In the .h file, declare a new Potentiometer class.
 * The class should have:
 *   private:
 *     - _potPin (use underscores (_) for all private variables)
 *   public:
 *     - Potentiometer (the constructor)
 *     - potRead();
 *     - potReadPercent();
 * 
 * The constructor should take an int parameter (the pin number)
 *   and set the _potPin variable, as well as declare the pinMode.
 * 
 * The other functions do the same as the did.
 */

// Include the library just written
#include "Potentiometer.h"

// Declare a Potentiometer object 
Potentiometer pot1(A0);

void setup() 
{
  // Set up Serial
  Serial.begin(9600);
  delay(100);
}

void loop() 
{
  // Print something
  Serial.print(pot1.potRead());
  Serial.print(" : ");
  Serial.println(pot1.potReadPercent());

  // Delay so that the data is actually readable
  delay(100);
}
