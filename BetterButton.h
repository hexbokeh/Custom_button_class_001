#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class BetterButton
{
  public:
    BetterButton(int _buttonPin, int _buttonNum);
    
    void process();
    void pressHandler(void (*f)(int));
    void releaseHandler(void (*f)(int));
    void (*pressCallback)(int);
    void (*releaseCallback)(int);

    int buttonNum;
    int buttonPin;
    bool buttonState;
    bool lastButtonState;

  private:
};

#endif
