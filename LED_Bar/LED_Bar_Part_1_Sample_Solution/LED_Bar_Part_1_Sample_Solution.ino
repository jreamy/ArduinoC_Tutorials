/*
 * Starting simply, set up an LED on pin 13, turn it on off setup, then have
 *   it flash regularly in loop
 */

// Pin declaration
int LEDpin = 13;

void setup() 
{
  pinMode(LEDpin, OUTPUT);
  digitalWrite(LEDpin, LOW);
}

void loop() 
{
  digitalWrite(LEDpin, HIGH);
  delay(500);

  digitalWrite(LEDpin, LOW);
  delay(500);
}
