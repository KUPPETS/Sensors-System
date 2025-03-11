#include "MoistureSensor.h"

MoistureSensor::MoistureSensor(int pin) : sensorPin(pin) {}

void MoistureSensor::begin() {
    pinMode(sensorPin, INPUT);
}

int MoistureSensor::readValue() {
    return analogRead(sensorPin);
}

void MoistureSensor::printValue() {
    int value = readValue();
    Serial.print("Moisture Level: ");
    Serial.println(value);
}