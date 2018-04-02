#include "Arduino.h"
#include "BetterButton.h"

BetterButton::BetterButton(int _buttonPin, int _buttonNum)
{
  buttonPin = _buttonPin;
  buttonNum = _buttonNum;
  buttonState = 0;
  lastButtonState = 0;

  pinMode(buttonPin, INPUT);
}

void BetterButton::process()
{
  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && buttonState == HIGH) {
    pressCallback(buttonNum);
  }
  if (lastButtonState == HIGH && buttonState == LOW) {
    releaseCallback(buttonNum);
  }
}

void BetterButton::pressHandler(void (*f)(int))    //button down
{
  pressCallback = *f;
}

void BetterButton::releaseHandler(void (*f)(int))  //button release
{
  releaseCallback = *f;
}
