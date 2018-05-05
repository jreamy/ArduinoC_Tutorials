/*
 * In this file, write a simple button debounce, which prints whenever the button
 *   is pressed or released.
 * 
 * Look up what debouncing is (https://www.arduino.cc/en/Tutorial/Debounce)
 * Look up the millis() function (https://www.arduino.cc/reference/en/language/functions/time/millis/)
 * 
 * Rewrite the code from the debounce example using pin 5 for the button in
 *   the function 'updateButtonState'.  Ignore the LED code.  Move the code 
 *   to update the last state to the beginning of the function.
 * 
 * In loop, call the function and print something if the state != the last state.
 * 
 */

// Global variables
int pin = 5;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

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
  if (buttonState != lastButtonState)
  {
    Serial.println("Button Event");
  }
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
    }
  }

  // Update the last state
  lastButtonState = reading;
}



