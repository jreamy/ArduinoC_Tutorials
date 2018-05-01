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
  float average = calculateAverage();

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

  // Set the initial output
  output = nums[0];

  // Iterate through all the elements in the array
  for(int i = 0; i < 6; i++)
  {
    // Check if the element is larger than the currently held max
    if (output < nums[i])
    {
      // Update the current max if needed
      output = nums[i];
    }
  }

  // Return the return variable
  return output;
}

// calculateAverage
float calculateAverage()
{
  // Declare return variable
  float output;

  // Declare variables for computation
  float total = 0;

  // Iterate through the array and calculate the total
  for (int i = 0; i < 6; i++)
  {
    total += nums[i];
  }

  // Set the output to the total / the number of elements
  output = total / 6;

  // Return the output
  return output;
}

// calculateSum
float calculateSum()
{
  // Declare return variable
  float output;

  // Iterate through the array and calculate the total
  for (int i = 0; i < 6; i++)
  {
    output += nums[i];
  }

  // Return the output
  return output;
}




