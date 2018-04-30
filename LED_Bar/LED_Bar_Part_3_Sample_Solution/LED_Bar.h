

#ifndef LED_Bar_h
#define LED_Bar_h

#include "Arduino.h"

class LED_Bar
{
  private:
    int pinNumbers[5];
    void setPin(int pinNumber);
  public:
    LED_Bar(int pin1, int pin2, int pin3, int pin4, int pin5);
    void displayNumber(int number);
};

#endif
