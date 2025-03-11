#ifndef FLUIDSENSOR_H
#define FLUIDSENSOR_H

#include <Arduino.h>

class FluidSensor {
public:
    FluidSensor(int pin);
    void begin();
    int readValue();
    void printValue();

private:
    int sensorPin;
};

#endif // FLUIDSENSOR_H