#ifndef JOYSTICKCLASS_H
#define JOYSTICKCLASS_H

#include <Arduino.h>

class JoyStick {
public:
    JoyStick(int xPin, int yPin, int buttonPin);
    void begin();
    void readValues();
    int getXValue();
    int getYValue();
    int getButtonState();

private:
    int xPin, yPin, buttonPin;
    int xVal, yVal, buttonState;
};

#endif