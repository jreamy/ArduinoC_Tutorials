

#include "Arduino.h"
#include "Potentiometer.h"


/* ============================================= *
 *                 Public Functions              *
 * ============================================= */

Potentiometer::Potentiometer(int pinNumber)
{
  _potPin = pinNumber;
  pinMode(_potPin, INPUT);
}

int Potentiometer::potRead()
{
  return analogRead(_potPin);
}

int Potentiometer::potReadPercent()
{
  return map(this->potRead(), 0, 1023, 0, 100);
}

