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
  // All Serial input for this project should be entered in the form
  // (int) (operator) (int) = 

  // For the next steps it is helpful to print what you have parsed at each step
  
  // Get the first int

  // Get the operator 

  // Check if the operator is '!' in which case, set b to something and
  // proceed, otherwise, get another int
  
  // Send the integers and the operator to the new calculate function
  // And print the output
  Serial.println(calculate(        ));

  // Clear the last characters sent in
  
}


// NextInt
int nextInt()
{
  // Use Serial.available() and a while loop to wait until there is serial data
  
  
  // Then return the integer
  
}

// NextChar
// Write a function similar to nextInt which returns only a char



// Calculate
int calculate(                )
{
  // Set up a return variable
  int output;
  
  // Use a switch case to call the correct function
  switch (    ) // this should hold the input character 
  {
    case '+':
      output = addition(     ); // this should hold the input integers
      break;
    case '-':
      // fill in the rest 
  }

  // Return the output
  
}

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



// Exponent



// Factorial






