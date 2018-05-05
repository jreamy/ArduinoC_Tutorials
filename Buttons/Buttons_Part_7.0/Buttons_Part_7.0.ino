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


// Include the library


// Initialize a Buttons object called buttons

void setup()
{
  // Begin Serial
  
  
  // Initialize a couple buttons calling attachButton
  
  
}

void loop()
{
  // Update the button states
  

  // Call the justPressed and justReleased functions to see what
  //   the result is
  
  
}

