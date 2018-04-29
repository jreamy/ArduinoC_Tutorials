/*
 * In this file, write simple calculator functions:
 *  - addition (example)
 *  - subtraction
 *  - multiplication
 *  - division
 *  - modulo
 *  - exponent
 *  - factorial
 *  
 * Then in setup, print sample calculations to make sure your functions work
 *  
 * Try printing 3 / 2, look up integer division starting here: "https://www.arduino.cc/reference/en/language/structure/arithmetic-operators/division/"
 */


void setup()
{
  // Begin Serial communication
  Serial.begin(9600);
  delay(100); // This is just generally good form for opening the Serial monitor
  
  // Test your functions here:

  // Addition
  Serial.print("5 + 6 = ");
  Serial.println(addition(5, 6));

  // Subtraction

  // Multiplication

  // Division

  // Modulo

  // Exponent

  // Factorial
  
}


// Don't do anything with the void loop for now
void loop(){}

// Addition
int addition(int a, int b)
{
  return a + b;
}

// Subtraction
int subtraction(int a, int b)
{
  
}

// Multiplication



// Division



// Modulo
// Look up the modulo operator: "https://www.arduino.cc/reference/en/language/structure/arithmetic-operators/modulo/"
// Use a while loop to achieve the same effect without using the "%" operator



// Exponent
// Use a for loop 



// Factorial
// Use a for loop





