#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include <Arduino.h>

class MoistureSensor {
public:
    MoistureSensor(int pin);
    void begin();
    int readValue();
    void printValue();

private:
    int sensorPin;
};

#endif // MOISTURESENSOR_H