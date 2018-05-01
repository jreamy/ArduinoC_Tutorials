/*
 * Functions are foundational to all code.
 * Read about them here: https://www.arduino.cc/en/Reference/FunctionDeclaration
 * 
 * In this program, write functions that find the max value,
 *   the average, and the sum of the global array.
 * 
 * Functions go below the void loop.
 */

// Global variables
float nums[6] = {.002, 3.142, 9.654, 765.0, 9.999, -34};

void setup()
{
  // Open Serial for printing to the monitor
  Serial.begin(9600);

  // Call the finMaximum function
  float maximum = findMaximum();
  
  // Call the calculateAverage function
  float avgerage = calculateAverage();

  // Call the calculateSum function
  float sum = calculateSum();

  // Print the maximum:
  Serial.print("Max : ");
  Serial.println(maximum);

  // Print the average:
  Serial.print("Avg : ");
  Serial.println(average);

  // Print the sum
  Serial.print("Sum : ");
  Serial.println(sum);
}


void loop() 
{
  // Do nothing
}

// findMaximum
float findMaximum() // this function returns a float 
{
  // Declare a return variable
  float output;

  // The code to find the maximum goes here
  

  // Return the return variable
  return output;
}

// calculateAverage
float calculateAverage()
{
  
}

// calculateSum






