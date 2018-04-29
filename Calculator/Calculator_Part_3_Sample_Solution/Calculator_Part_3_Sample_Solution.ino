/*
 * In this project, we move the calculator functions into their own library
 * 
 * Look up how to write libraries: "https://www.arduino.cc/en/Hacking/LibraryTutorial"
 * 
 * In this example I have included the file structure needed 
 * 
 * 
 */

// Initialize a global Calculator object named calculator
Calculator calculator;


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
  Serial.println(calculator.calculate(a, b, op));
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


