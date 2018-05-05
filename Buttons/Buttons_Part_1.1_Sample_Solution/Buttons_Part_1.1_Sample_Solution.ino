/*
 * What happens when you run the current code?
 * 
 * The debounce in the code allows the state to not equal the last 
 *   state for long enough that 10-20 events should print each time
 *   you press the button.  
 *   
 * Look back at the example debounce code (https://www.arduino.cc/en/Tutorial/Debounce)
 *   Their code only turns on the LED when the button state changes
 *   to HIGH.  That is a hard coded event, which won't be much use
 *   in a library.  Instead, we need a boolean that we set true
 *   when the button switches to high, and that gets reset to low 
 *   once we check it.
 * 
 * Add: 
 *  - a global boolean justPressed, and one justReleased
 *  - in the updateButtonState function, an if statement that 
 *      sets justPressed to true if the button state just changed
 *      to HIGH, and one that sets justReleased to true if the 
 *      button state just changed to LOW.
 * 
 * Write:
 *  - a function, wasPressed, which returns the state of 
 *      justPressed, and sets justPressed to false.
 *  - a function, wasReleased, which returns the state of 
 *      justReleased, and sets justReleased to false.
 * 
 * Change the code in the void loop to test your wasPressed and 
 *   wasReleased functions
 * 
 */

// Global variables
int pin = 5;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// Booleans
boolean justPressed = false;
boolean justReleased = false;

void setup()
{
  // Begin Serial
  Serial.begin(9600);
  delay(50);

  // Initialize the pin
  pinMode(pin, INPUT);
}

void loop()
{
  // Call the update function
  updateButtonState();

  // Print something if the state changed
  if (wasPressed())
  {
    Serial.println("Just Pressed");
  }
  if (wasReleased())
  {
    Serial.println("Just Released");
  }
}

// wasPressed
boolean wasPressed()
{
  // Set up return variable
  boolean output = justPressed;

  // Set the global false
  justPressed = false;

  // Return the output
  return output;
}


// wasReleased
boolean wasReleased()
{
  // Set up return variable
  boolean output = justReleased;

  // Set the global false
  justReleased = false;

  // Return the output
  return output;
}


// updateButtonState
void updateButtonState()
{
  // Declare a local variable 
  int reading;

  // Get the reading
  reading = digitalRead(pin);

  // Check if the reading is not what the state is
  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  // Check if the required delay has occured between state changes
  if ((millis() - lastDebounceTime > debounceDelay))
  {
    // Update the state
    if (reading != buttonState)
    {
      buttonState = reading;

      // If just pressed
      if (buttonState == HIGH)
      {
        justPressed = true;
      }

      // If just released
      if (buttonState == LOW)
      {
        justReleased = true;
      }
    }
  }

  // Update the last state
  lastButtonState = reading;
}
