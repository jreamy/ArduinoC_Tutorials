/*
 * For this project, build an array-driven set of LEDs
 * 
 * Look up arrays (https://www.arduino.cc/reference/en/language/variables/data-types/array/)
 * 
 * Store 5 pin numbers in an int array
 * 
 * Write:
 *  - a function "setPin" that initializes the LED (similar to the setup() 
 *        of the last program)
 *  - a function "LED_Bar" which takes 5 ints (pin numbers), 
 *        adds them to the array, and initializes them
 *  - a function "displayNumber" that takes a number 0 - 100 and turns on the corresponding 
 *        number of pins
 *  
 * In Setup call the LED_Bar function
 * 
 * In loop run the displayNumber function with different values and delays to see it working
 */

// Array for the pin numbers
int pinNumbers[5];

void setup() 
{
  LED_Bar(9, 10, 11, 12, 13);
}

void loop() 
{
  for (int i = 0; i < 120; i += 10)
  {
    displayNumber(i);
    delay(100);
  }
}

// setPin
void setPin(int pinNum)
{
  pinMode(pinNum, OUTPUT);
  digitalWrite(pinNum, LOW);
}

// LED_Bar
void LED_Bar(int pin1, int pin2, int pin3, int pin4, int pin5)
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
    setPin(pinNumbers[i]);
  }
}

// displayNumber
/*
 * Number of LEDs on:
 *  x  <  11  :  0
 * 11  -  30  :  1
 * 31  -  50  :  2
 * 51  -  70  :  3
 * 71  -  90  :  4
 * 90  <   x  :  5
 */
void displayNumber(int number)
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


