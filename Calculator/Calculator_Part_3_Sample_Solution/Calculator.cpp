

#include "Arduino.h"
#include "Calculator.h"


/* ============================================= *
 *                 Public Functions              *
 * ============================================= */
 
// The constructor
Calculator::Calculator()
{
  // Which does nothing
}

// Calculate
int Calculator::calculate(int a, int b, char op)
{
  // Set up a return variable
  int output;
  
  // Use a switch case to call the correct function
  switch (op)
  {
    case '+':
      output = this->addition(a, b);
      break;
    case '-':
      output = this->subtraction(a, b);
      break;
    case '*':
      output = this->multiplication(a, b);
      break;
    case '/':
      output = this->division(a, b);
      break;
    case '%':
      output = this->modulo(a, b);
      break;
    case '^':
      output = this->exponent(a, b);
      break;
    case '!':
      output = this->factorial(a);
      break;
    default:
      // This is here in case an invalid character was sent in
      output = 1;
  }

  // Return the output
  return output;
}


/* ============================================= *
 *                Private Functions              *
 * ============================================= */

// Addition
int Calculator::addition(int a, int b)
{
  return a + b;
}


// Subtraction
int Calculator::subtraction(int a, int b)
{
  return a - b;
}


// Multiplication
int Calculator::multiplication(int a, int b)
{
  return a * b;
}


// Division
int Calculator::division(int a, int b)
{
  return a / b;
}


// Modulo
int Calculator::modulo(int a, int b)
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
int Calculator::exponent(int a, int b)
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
int Calculator::factorial(int a)
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



