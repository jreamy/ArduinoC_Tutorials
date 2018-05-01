/*
 * Arrays are foundational to all data storage and processing.
 * Read about them here: https://www.arduino.cc/reference/en/language/variables/data-types/array/
 * And here: https://www.arduino.cc/en/Tutorial/Arrays
 * 
 * Look up for loops, while loops, and do while loops:
 *  - for: https://www.arduino.cc/reference/en/language/structure/control-structure/for/
 *  - while: https://www.arduino.cc/reference/en/language/structure/control-structure/while/
 *  - do while: https://www.arduino.cc/reference/en/language/structure/control-structure/dowhile/
 * 
 * In this program, print the average of the array
 */

void setup()
{
  // Open Serial for printing to the monitor
  Serial.begin(9600);
  
  // Declare an int array
  int nums[7] = {0, 2, 5, 7, 8, 4, 3};
  
  // Use a for loop to average the array
  int total = 0;
  for (int i = 0; i < 7; i++)
  {
    total = total + nums[i];
  }

  float avg = total / 7.0;

  // Print the average
  Serial.println(avg);
}


void loop() 
{
  // Do nothing
}
