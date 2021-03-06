/*
 * In this file, revise the updateButtonState function to implement
 *   arrays
 * 
 * Write:
 *  - a function, updateButtonState, that takes a pin number and
 *      updates the corresponding button's data
 *  - a function, updateButtonStates, that takes no parameters
 *      and updates all the buttons attached (calling the other
 *      function)
 * 
 * Look back at the code from Part 1 and implement similar code,
 *   which uses array indexing
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
}

void loop()
{
  // Update the button states
  updateButtonStates();

  // Iterate through the buttons and print their current state
  Serial.print(buttonState[0]);
  Serial.print(" ");
  Serial.println(buttonState[1]);
}

// updateButtonState
void updateButtonState(int pinNum)
{
  // Set up local variables
  int pinLocation;
  int reading;
  
  // Check that the pin is one of the buttons
  if (isAttached(pinNum))
  {
    // Get the location of the data
    pinLocation = pinPosition(pinNum);

    // Get the reading
    reading = digitalRead(pinNum);

    // Check if the reading is not what the state is
    if (reading != lastButtonState[pinLocation])
    {
      lastDebounceTime[pinLocation] = millis();
    }

    // Check if the required delay has occured between state changes
    if ((millis() - lastDebounceTime[pinLocation]) > debounceDelay[pinLocation])
    {
      // Update the buttonState
      if (buttonState[pinLocation] != reading)
      {
        buttonState[pinLocation] = reading;
      }
    }

    // Update the last state
    lastButtonState[pinLocation] = reading;
  }
}

// updateButtonStates
void updateButtonStates()
{
  // Iterate through all the buttons
  for (int i = 0; i < numberOfButtons; i++)
  {
    // Update the button
    updateButtonState(pins[i]);
  }
}

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



