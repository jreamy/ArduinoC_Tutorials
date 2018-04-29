/*
 * Copy your calculator functions into this file
 * 
 * The goal of this file is to write a function that parses input from the 
 *   Serial monitor into usable commands.
 * 
 * Look up the Serial object here: "https://www.arduino.cc/reference/en/language/functions/communication/serial/"
 * The primary functions we will use are: 
 *  - parseInt()
 *  - read()
 *  - print()
 *  - println()
 *  
 * Write a function that waits for Serial input, then returns an integer
 * Write a function that waits for Serial input, then returns a character
 * 
 * Write a new function that takes two integers (int) and a character (char) 
 *   the char will hold the operator (+-/*%^!)
 */


void setup()
{
  // Begin Serial communication
  Serial.begin(9600);
  delay(100); // This is just generally good form for opening the Serial monitor
}


// This runs continuously after Setup
void loop()
{
  // Variable declaration
  int a;
  int b;
  char op;
  
  // All Serial input for this project should be entered in the form
  // (int) (operator) (int) = 

  // For the next steps it is helpful to print what you have parsed at each step
  
  // Get the first int
  a = nextInt();

  // Print the int
  Serial.print(a);

  // Clear and print the ' '
  Serial.print(nextChar());
  
  // Get the operator 
  op = nextChar();

  // Print the operator
  Serial.print(op);

  // Clear and print the ' '
  Serial.print(nextChar());

  // Check if the operator is '!' in which case, set b to something and
  // proceed, otherwise, get another int
  if (op == '!')
  {
    b = 0;
  }
  else
  {
    // Get the second int
    b = nextInt();

    // Print the second int
    Serial.print(b);

    // Clear and print the ' '
    Serial.print(nextChar());
  }

  // Clear and print the last characters sent in ('= ')
  Serial.print(nextChar());
  Serial.print(nextChar());
  
  // Send the integers and the operator to the new calculate function
  // And print the output
  Serial.println(calculate(a, b, op));
}


// NextInt
int nextInt()
{
  // Wait until there is Serial data
  while (!Serial.available())
    ;
  
  // Then get and return the integer
  return Serial.parseInt();
}

// NextChar
char nextChar()
{
  // Wait until there is Serial data
  while (!Serial.available())
    ;

  // Then get and return the char
  return (char) Serial.read();
}


// Calculate
int calculate(int a, int b, char op)
{
  // Set up a return variable
  int output;
  
  // Use a switch case to call the correct function
  switch (op)
  {
    case '+':
      output = addition(a, b);
      break;
    case '-':
      output = subtraction(a, b);
      break;
    case '*':
      output = multiplication(a, b);
      break;
    case '/':
      output = division(a, b);
      break;
    case '%':
      output = modulo(a, b);
      break;
    case '^':
      output = exponent(a, b);
      break;
    case '!':
      output = factorial(a);
      break;
    default:
      // This is here in case an invalid character was sent in
      output = 1;
  }

  // Return the output
  return output;
}

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





