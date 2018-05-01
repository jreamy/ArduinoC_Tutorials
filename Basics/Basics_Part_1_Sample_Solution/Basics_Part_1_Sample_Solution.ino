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
 * In this program, print all of the elements of the array
 */

void setup()
{
  // Open Serial for printing to the monitor
  Serial.begin(9600);
  
  // Declare an int array
  int nums[7] = {0, 2, 5, 7, 8, 4, 3};
  
  // Use a for loop to print all the elements
  for (int i = 0; i < 7; i++)
  {
    Serial.println(nums[i]);
  }
  
  // Use a while loop to print all the elements
  int i = 0;
  while (i < 7)
  {
    Serial.println(nums[i]);
    i++;
  }
  
  // Use a do while loop to print all the elements
  int j = 0;
  do
  {
    Serial.println(nums[j]);
    j++;
  } while (j < 7);
  
}


void loop() 
{
  // Do nothing
}
