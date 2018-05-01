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
 * In this program, check if 5, and then if 6 are in the array
 */

void setup()
{
  // Open Serial for printing to the monitor
  Serial.begin(9600);
  
  // Declare an int array
  int nums[7] = {0, 2, 5, 7, 8, 4, 3};
  
  // Use a loop to check if 5 is in the array
  int i = 0;
  boolean found5 = false;
  while (i < 7 && !found5)
  {
    if (nums[i] == 5)
    {
      found5 = true;
    }
    else
    {
      i++;
    }
  }
  
  // Print if 5 is in the array
  Serial.println(found5);
  
  // Use a loop to check if 6 is in the array
  int j = 0;
  boolean found6 = false;
  while (j < 7 && !found6)
  {
    if (nums[j] == 6)
    {
      found6 = true;
    }
    else
    {
      j++;
    }
  }
  
  // Print it 6 is in the array
  Serial.println(found6);
  
  // Try to achieve this without checking every number in the array if the element is found
}


void loop() 
{
  // Do nothing
}
