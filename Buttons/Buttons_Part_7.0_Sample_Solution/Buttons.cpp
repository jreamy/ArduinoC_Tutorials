

#include "Arduino.h"
#include "Buttons.h"


/* ============================================= *
 *                 Public Functions              *
 * ============================================= */
 
// The constructor
Buttons::Buttons()
{
  // Just set the number of buttons to 0
  numberOfButtons = 0;
}

// getButtonState
int Buttons::getButtonState(int pinNum)
{
  // Set up a return variable and local variable
  int output = LOW;
  int pinLocation;

  // Check if the pin is one in the list
  if (this->isAttached(pinNum))
  {
    // Get the location
    pinLocation = this->pinPosition(pinNum);

    // Get the last state of the corresponding button
    output = buttonState[pinLocation];
  }

  // Return the output
  return output;
}

// getLastButtonState
int Buttons::getLastButtonState(int pinNum)
{
  // Set up a return variable and local variable
  int output = LOW;
  int pinLocation;

  // Check if the pin is one in the list
  if (this->isAttached(pinNum))
  {
    // Get the location
    pinLocation = this->pinPosition(pinNum);

    // Get the last state of the corresponding button
    output = lastButtonState[pinLocation];
  }

  // Return the output
  return output;
}

// wasPressed
boolean Buttons::wasPressed(int pinNum)
{
  // Set up return variable and local variable
  boolean output = false;
  int pinLocation;
  
  // Check if the pin is one attached
  if (this->isAttached(pinNum))
  {
    // Get the location of the pin
    pinLocation = this->pinPosition(pinNum);
    
    // Get the justPressed state
    output = justPressed[pinLocation];

    // Set the justPressed state to false
    justPressed[pinLocation] = false;
  }

  // Return the output
  return output;
}

// wasReleased
boolean Buttons::wasReleased(int pinNum)
{
  // Set up return variable and local variable
  boolean output = false;
  int pinLocation;
  
  // Check if the pin is one attached
  if (this->isAttached(pinNum))
  {
    // Get the location of the pin
    pinLocation = this->pinPosition(pinNum);
    
    // Get the justReleased state
    output = justReleased[pinLocation];

    // Set the justReleased state to false
    justReleased[pinLocation] = false;
  }

  // Return the output
  return output;
}

// setDebounceDelay
void Buttons::setDebounceDelay(int pinNum, unsigned long newDebounceDelay)
{
  // Check if the pin is actually one of the buttons
  if (this->isAttached(pinNum))
  {
    // Set the debounceDelay
    debounceDelay[this->pinPosition(pinNum)] = newDebounceDelay;
  }
}

// setDebounceDelays
void Buttons::setDebounceDelays(unsigned long newDebounceDelay)
{
  // Iterate through the buttons
  for (int i = 0; i < numberOfButtons; i++)
  {
    // Set the debounce of each button
    debounceDelay[i] = newDebounceDelay;
  }
}

// updateButtonState
void Buttons::updateButtonState(int pinNum)
{
  // Set up local variables
  int pinLocation;
  int reading;
  
  // Check that the pin is one of the buttons
  if (this->isAttached(pinNum))
  {
    // Get the location of the data
    pinLocation = this->pinPosition(pinNum);

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
  
        // If it was just pressed
        if (buttonState[pinLocation] == HIGH)
        {
          justPressed[pinLocation] = true;
        }
        else  // Otherwise, it was just released
        {
          justReleased[pinLocation] = true;
        }
      }
    }

    // Update the last state
    lastButtonState[pinLocation] = reading;
  }
}

// updateButtonStates
void Buttons::updateButtonStates()
{
  // Iterate through all the buttons
  for (int i = 0; i < numberOfButtons; i++)
  {
    // Update the button
    updateButtonState(pins[i]);
  }
}

// attachButton
void Buttons::attachButton(int pinNum)
{
  // Check if the button is already attached, and there's room
  if (!this->isAttached(pinNum) && numberOfButtons < NUM_OF_BUTTONS)
  {
    // Use the number of buttons as the location in the array
    //   to initialize the data
    pins[numberOfButtons] = pinNum;
    pinMode(pinNum, INPUT);
    
    buttonState[numberOfButtons] = LOW;
    lastButtonState[numberOfButtons] = LOW;

    lastDebounceTime[numberOfButtons] = millis();
    debounceDelay[numberOfButtons] = 50;

    justPressed[numberOfButtons] = false;
    justReleased[numberOfButtons] = false;

    // Increase the number of attached buttons
    numberOfButtons += 1;
  }
}

// detachButton
void Buttons::detachButton(int pinNum)
{
  // Local variable for storing the location
  int pinLocation;
  
  // Check if it's attached
  if (this->isAttached(pinNum))
  {
    // Get the location
    pinLocation = this->pinPosition(pinNum);

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

      justPressed[i] = justPressed[i + 1];
      justReleased[i] = justReleased[i + 1];
      
      i++;
    }

    // Decrease the number of buttons
    numberOfButtons -= 1;
  }
}


/* ============================================= *
 *                Private Functions              *
 * ============================================= */

// isAttached
boolean Buttons::isAttached(int pinNum)
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
int Buttons::pinPosition(int pinNum)
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


