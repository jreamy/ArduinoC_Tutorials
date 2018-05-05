/*
 * The purpose of the remaining Buttons projects is to build a
 *   library which holds and debounces multiple buttons.
 *   
 * We'll develop it one or two functions at a time.
 * 
 * Start by looking up the #define command (https://www.arduino.cc/reference/en/language/structure/further-syntax/define/)
 * 
 * Define the number of buttons that will be used, NUM_OF_BUTTONS, 
 *   and then initialize arrays of the corresponding length.
 *   
 * Start simple with only 3 or so buttons.
 * 
 * Write:
 *  - a function, isAttached, that takes a pin number and checks
 *      if it is already in the pins array
 *  - a function, pinPosition, that take a pin number and returns
 *      the location in the pins array (-1 if not in the array)
 * 
 * You will need an extra variable to keep track of the number of
 *   buttons already added, you should not iterate through more of
 *   the array than there are buttons.
 */

// Define how many buttons will be used


// Variable arrays (add the rest)
int pins[NUM_OF_BUTTONS];

int buttonState[      ];



void setup()
{
  // Begin Serial


  // Initialize the arrays by indexing ('pins[x] = y')


  // Test your functions by printing out various function calls
  
}

void loop() {}

// isAttached


// pinPosition




