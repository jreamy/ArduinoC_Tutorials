/*
 * Finally, we need to actually put the functions into a library.
 * 
 * Open the tabs needed for the Buttons library (.h and .cpp files).
 * 
 * Look up conditional compilation (https://www.cs.auckland.ac.nz/references/unix/digital/AQTLTBTE/DOCU_078.HTM).
 *   If you look at the previous library examples, you'll notice
 *   that we've already used #ifndef and we use #define.  Include 
 *   an #ifndef statement at the top of the library beneath the
 *   #include statement to #define NUM_OF_BUTTONS to some default.
 *   This lets you include your library in other applications
 *   and define the number of buttons it will allocate memory for.
 * 
 * Think about what things should be public and what should be 
 *   private in the library.  Data is generally private where 
 *   functions are public, but functions such as pinLocation don't 
 *   need to be accessible outside of the library.
 * 
 * Remember that functions called by other functions withing the 
 *   library, such as a function calling 'isAttached(pinNum)' 
 *   must use 'this->isAttached(pinNum)'.
 * 
 * Remember to add a constructor.
 * 
 */

// Define how many buttons will be used
#define NUM_OF_BUTTONS 3

// Include the library
#include "Buttons.h"

// Initialize a buttons object
Buttons buttons;

void setup()
{
  // Begin Serial
  Serial.begin(9600);
  delay(50);
  
  // Initialize a couple buttons calling attachButton
  buttons.attachButton(4);
  buttons.attachButton(5);
  
}

void loop()
{
  // Update the button states
  buttons.updateButtonStates();

  // Call the justPressed and justReleased functions to see what
  //   the result is
  if (buttons.wasPressed(4))
  {
    Serial.println("Button 4 pressed");
  }
  else if (buttons.wasReleased(4))
  {
    Serial.println("Button 4 released");
  }

  if (buttons.wasPressed(5))
  {
    Serial.println("Button 5 pressed");
  }
  else if (buttons.wasReleased(5))
  {
    Serial.println("Button 5 released");
  }
}

