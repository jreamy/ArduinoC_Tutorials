/*
 * In this project, we move the calculator functions into their own library
 * 
 * Look up how to write libraries: "https://www.arduino.cc/en/Hacking/LibraryTutorial"
 * 
 * In this example I have included the file structure needed 
 * 
 * 
 */

// Initialize a global Calculator object named calc


void setup()
{
  // Begin Serial communication
  Serial.begin(9600);
  delay(100); // This is just generally good form for opening the Serial monitor
}


// This runs continuously after Setup
void loop()
{
  // Copy most of your code from the last program, but use
  // the calculator object funtions
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


