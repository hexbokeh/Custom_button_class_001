#include <MIDI.h>
#include "BetterButton.h"

int button1Pin = 32;
int button2Pin = 31;
int button3Pin = 30;
int button4Pin = 29;
BetterButton btn1(button1Pin, 0);
BetterButton btn2(button2Pin, 1);
BetterButton btn3(button3Pin, 2);
BetterButton btn4(button4Pin, 3);

void setup() {
  Serial.begin(9600);
  btn1.pressHandler(onPress);
  btn1.releaseHandler(onRelease);
  btn2.pressHandler(onPress);
  btn2.releaseHandler(onRelease);
  btn3.pressHandler(onPress);
  btn3.releaseHandler(onRelease);
  btn4.pressHandler(onPress);
  btn4.releaseHandler(onRelease);
}

void loop() {
  btn1.process();
  btn2.process();
  btn3.process();
  btn4.process();
}

void onPress(int buttonNum)
{
  usbMIDI.sendNoteOn(60 + buttonNum, 127, 1);
  Serial.print(buttonNum);
  Serial.println(" on");
}

void onRelease(int buttonNum)
{
  usbMIDI.sendNoteOff(60 + buttonNum, 0, 1);
  Serial.print(buttonNum);
  Serial.println(" off");
}

