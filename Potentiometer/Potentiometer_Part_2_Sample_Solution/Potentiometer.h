

#ifndef Potentiometer_h
#define Potentiometer_h

#include "Arduino.h"

class Potentiometer
{
  private:
    int _potPin;
  public:
    Potentiometer(int pinNumber);
    int potRead();
    int potReadPercent();
};

