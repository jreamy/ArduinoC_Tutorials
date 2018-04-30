

#include "Arduino.h"
#include "LED_Bar.h"


/* ============================================= *
 *                 Public Functions              *
 * ============================================= */

// The constructor
LED_Bar::LED_Bar(int pin1, int pin2, int pin3, int pin4, int pin5)
{
  // Add the pins to the array
  pinNumbers[0] = pin1;
  pinNumbers[1] = pin2;
  pinNumbers[2] = pin3;
  pinNumbers[3] = pin4;
  pinNumbers[4] = pin5;

  // Iterate through the array
  for (int i = 0; i < 5; i++)
  {
    // Set up each pin
    this->setPin(pinNumbers[i]);
  }
}

void LED_Bar::displayNumber(int number)
{
  // Write all the pins low
  
  // Iterate through the pins and turn them all off
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(pinNumbers[i], LOW);
  }

  // If it's greater than 10, turn on LED 1
  if (number > 10)
  {
    digitalWrite(pinNumbers[0], HIGH);
  }

  // If it's greater than 30, turn on LED 2 also
  if (number > 30)
  {
    digitalWrite(pinNumbers[1], HIGH);
  }

  // If it's greater than 50, turn on LED 3 also
  if (number > 50)
  {
    digitalWrite(pinNumbers[2], HIGH);
  }

  // If it's greater than 70, turn on LED 4 also
  if (number > 70)
  {
    digitalWrite(pinNumbers[3], HIGH);
  }

  // If it's greater than 90, turn on LED 5 also
  if (number > 90)
  {
    digitalWrite(pinNumbers[4], HIGH);
  }
}


/* ============================================= *
 *                Private Functions              *
 * ============================================= */

void LED_Bar::setPin(int pinNumber)
{
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
}


