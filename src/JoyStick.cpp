#include "JoyStickClass.h"

JoyStick::JoyStick(int xPin, int yPin, int buttonPin)
    : xPin(xPin), yPin(yPin), buttonPin(buttonPin), xVal(0), yVal(0), buttonState(0) {}

void JoyStick::begin() {
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(buttonPin, INPUT_PULLUP);
}

void JoyStick::readValues() {
    xVal = analogRead(xPin);
    yVal = analogRead(yPin);
    buttonState = digitalRead(buttonPin);
}

int JoyStick::getXValue() {
    return xVal;
}

int JoyStick::getYValue() {
    return yVal;
}

int JoyStick::getButtonState() {
    return buttonState;
}