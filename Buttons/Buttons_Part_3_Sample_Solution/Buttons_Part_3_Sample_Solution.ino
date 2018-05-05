/*
 * In this file, develop functions to add and remove buttons
 *   from the arrays
 * 
 * Write:
 *  - a function, attachButton, that takes a pin number and adds 
 *      the needed data to the arrays.  This should also set the
 *      pinMode of the given pin to INPUT.
 *  - a function, detachButton, that takes a pin number and removes
 *      the corresponding data from the arrays, if it is attached
 *      
 * You will need to use the isAttached and pinPosition functions
 *   as well as iterating.
 * 
 * Look up how to remove an alement from an array (how to shift
 *   the rest of the array to overwrite the data in the location)
 */

// Define how many buttons will be used
#define NUM_OF_BUTTONS 3

// Variable arrays (add the rest)
int pins[NUM_OF_BUTTONS];

int buttonState[NUM_OF_BUTTONS];
int lastButtonState[NUM_OF_BUTTONS];

unsigned long lastDebounceTime[NUM_OF_BUTTONS];
unsigned long debounceDelay[NUM_OF_BUTTONS];

int numberOfButtons = 0;

void setup()
{
  // Begin Serial
  Serial.begin(9600);
  delay(50);
  
  // Initialize a couple buttons calling attachButton
  attachButton(4);
  attachButton(5);
  attachButton(6);
  
  // Test your functions by printing out various function calls
  Serial.println("Button on pin 4");
  Serial.print("isAttached : ");
  Serial.println(isAttached(4));
  Serial.print("pinPosition : ");
  Serial.println(pinPosition(4));

  Serial.println("Button on pin 5");
  Serial.print("isAttached : ");
  Serial.println(isAttached(5));
  Serial.print("pinPosition : ");
  Serial.println(pinPosition(5));

  Serial.println("Button on pin 6");
  Serial.print("isAttached : ");
  Serial.println(isAttached(6));
  Serial.print("pinPosition : ");
  Serial.println(pinPosition(6));
  
  // Detach a button and check its pin number again
  detachButton(5);

  Serial.println();

  Serial.println("Button on pin 4");
  Serial.print("isAttached : ");
  Serial.println(isAttached(4));
  Serial.print("pinPosition : ");
  Serial.println(pinPosition(4));

  Serial.println("Button on pin 5");
  Serial.print("isAttached : ");
  Serial.println(isAttached(5));
  Serial.print("pinPosition : ");
  Serial.println(pinPosition(5));

  Serial.println("Button on pin 6");
  Serial.print("isAttached : ");
  Serial.println(isAttached(6));
  Serial.print("pinPosition : ");
  Serial.println(pinPosition(6));
}

void loop() {}

// attachButton
void attachButton(int pinNum)
{
  // Check if the button is already attached, and there's room
  if (!isAttached(pinNum) && numberOfButtons < NUM_OF_BUTTONS)
  {
    // Use the number of buttons as the location in the array
    //   to initialize the data
    pins[numberOfButtons] = pinNum;
    pinMode(pinNum, INPUT);
    
    buttonState[numberOfButtons] = LOW;
    lastButtonState[numberOfButtons] = LOW;

    lastDebounceTime[numberOfButtons] = millis();
    debounceDelay[numberOfButtons] = 50;

    // Increase the number of attached buttons
    numberOfButtons += 1;
  }
}

// detachButton
void detachButton(int pinNum)
{
  // Local variable for storing the location
  int pinLocation;
  
  // Check if it's attached
  if (isAttached(pinNum))
  {
    // Get the location
    pinLocation = pinPosition(pinNum);

    // Shift all the data in the arrays past the point of the 
    //   pin position over one
    int i = pinLocation;
    while (i < numberOfButtons - 1)
    {
      // Set the data as the data at the next location (shift it)
      pins[i] = pins[i + 1];

      buttonState[i] = buttonState[i + 1];
      lastButtonState[i] = lastButtonState[i + 1];

      lastDebounceTime[i] = lastDebounceTime[i + 1];
      debounceDelay[i] = debounceDelay[i + 1];
      
      i++;
    }

    // Decrease the number of buttons
    numberOfButtons -= 1;
  }
}

// isAttached
boolean isAttached(int pinNum)
{
  // Set up a return variable
  boolean output = false;

  // Iterate through the buttons
  int i = 0;
  while (i < numberOfButtons && output == false)
  {
    // Check if the pin number is the current pin
    if (pinNum == pins[i])
    {
      // If it is, set the output to true
      output = true;
    }

    i++;
  }

  // Return the output
  return output;
}

// pinPosition
int pinPosition(int pinNum)
{
  // Set up a return variable
  int output = -1;

  // Iterate through the buttons
  int i = 0;
  while (i < numberOfButtons && output < 0)
  {
    // Check if the input pin is the same as the pin at the
    //   index in the array
    if (pinNum == pins[i])
    {
      // Set the location as the output location
      output = i;
    }

    i++;
  }

  // Return the output
  return output;
}




