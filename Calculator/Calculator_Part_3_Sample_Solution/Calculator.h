

#ifndef Calculator_h
#define Calculator_h

#include "Arduino.h"

class Calculator
{
  private:
    // This is where variables and functions that only can be used in 
    // Calculator.h or Calculator.cpp go

    // The individual functions are here, with their return 
    // type and parameters, which are all called by calculate 
    int addition(int a, int b);
    int subtraction(            );
    // Add the other function names here
    
  public:
    // This is where variables and functions that can be used in the main file,
    // or other files go

    // This is the constructor (all classes need one even if it does nothing)
    Calculator();

    // The calculate function
    int calculate(         );
    
};


#endif
