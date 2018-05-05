

#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

// Define the default number of buttons 
#ifndef NUM_OF_BUTTONS
#define NUM_OF_BUTTONS 10
#endif

class Buttons
{
  private:
    // Private variables
    int pins[NUM_OF_BUTTONS];
    int buttonState[NUM_OF_BUTTONS];
    int lastButtonState[NUM_OF_BUTTONS];
    unsigned long lastDebounceTime[NUM_OF_BUTTONS];
    unsigned long debounceDelay[NUM_OF_BUTTONS];
    int numberOfButtons;
    boolean justPressed[NUM_OF_BUTTONS];
    boolean justReleased[NUM_OF_BUTTONS];

    // Private functions
    boolean isAttached(int pinNum);
    int pinPosition(int pinNum);
    
  public:
    // Constructor
    Buttons();
    
    // Public Getters
    int getButtonState(int pinNum);
    int getLastButtonState(int pinNum);
    boolean wasPressed(int pinNum);
    boolean wasReleased(int pinNum);
    void setDebounceDelay(int pinNum, unsigned long newDebounceDelay);
    void setDebounceDelays(unsigned long newDebounceDelay);
    void updateButtonState(int pinNum);
    void updateButtonStates();
    void attachButton(int pinNum);
    void detachButton(int pinNum);
};

#endif
