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
  Serial.print("7 - 2 = ");
  Serial.println(subtraction(7, 2));
  
  // Multiplication
  Serial.print("8 * 9 = ");
  Serial.println(multiplication(8, 9));
  
  // Division
  Serial.print("5 / 2 = ");
  Serial.println(division(5, 2));

  // Modulo
  Serial.print("18 % 5 = ");
  Serial.println(modulo(18, 5));

  // Exponent
  Serial.print("3 ^ 5 = ");
  Serial.println(exponent(3, 5));

  // Factorial
  Serial.print("4! = ");
  Serial.println(factorial(4));
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
  return a - b;
}

// Multiplication
int multiplication(int a, int b)
{
  return a * b;
}


// Division
int division(int a, int b)
{
  return a / b;
}


// Modulo
int modulo(int a, int b)
{
  // Set up a return variable
  int output = a;

  // Iterate until output < b
  while (output >= b)
  {
    // Decrease the output by units of 
    output -= b;
  }

  // Return the output
  return output;
}


// Exponent
int exponent(int a, int b)
{
  // Set up a return variable
  int output = 1;

  // Loop a number of times equal to b
  for (int i = 0; i < b; i++)
  {
    // Multiply the output by the base
    output *= a;
  }

  // Return the output
  return output;
}



// Factorial
int factorial(int a)
{
  // Set up a return variable
  int output = 1;

  // Loop a number of times equal to a
  for (int i = 0; i < a; i++)
  {
    // Multiply by i (offset by 1 so it is 1 -> a not 0 -> a - 1)
    output *= (i + 1);
  }

  // Return the output
  return output;
}





