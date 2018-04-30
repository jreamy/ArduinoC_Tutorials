/*
 * In this project, we will simply be setting up a pot (potentiometer) (https://www.arduino.cc/en/tutorial/potentiometer)
 * 
 * Write:
 *  - variable declaration
 *  - pin setup 
 *  - Serial setup
 *  - a potRead function which returns the pin value
 *  - a potReadPercent function which returns the pin value as a percentage of the possible output
 */

// Declare the pin for the potentiometer
const int potPin = A0;

void setup() 
{
  // Serial setup
  Serial.begin(9600);
  delay(100);
  
  // Set the pin as an input 
  pinMode(A0, OUTPUT);
}

void loop() 
{
  // Print the output of the read function
  Serial.print(potRead());
  Serial.print(" : ");
  Serial.println(potReadPercent());

  // Delay so the data is actually readable
  delay(100);
}

// potRead()
int potRead()
{
  return analogRead(potPin);
}


// potReadPercent()
int potReadPercent()
{
  return map(potRead(), 0, 1023, 0, 100);
}



