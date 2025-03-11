#ifndef TEMPERATUREHUMIDITYSENSOR_H
#define TEMPERATUREHUMIDITYSENSOR_H

#include <Wire.h>
#include <Arduino.h>

class TemperatureHumiditySensor {
public:
    explicit TemperatureHumiditySensor();
    void begin();
    bool read(float &temperature, float &humidity);

private:
    bool init();
    static const uint8_t AHT21_ADDRESS = 0x38; // I2C address of AHT21
};

#endif // TEMPERATUREHUMIDITYSENSOR_H
