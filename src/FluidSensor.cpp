#include "FluidSensor.h"

FluidSensor::FluidSensor(int pin) : sensorPin(pin) {}

void FluidSensor::begin() {
    pinMode(sensorPin, INPUT);
}

int FluidSensor::readValue() {
    return analogRead(sensorPin);
}

void FluidSensor::printValue() {
    int value = readValue();
    Serial.print("Fluid Level: ");
    Serial.println(value);
}
