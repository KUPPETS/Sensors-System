#include <Wire.h>
#include "TemperatureHumiditySensor.h"

TemperatureHumiditySensor::TemperatureHumiditySensor() {}

void TemperatureHumiditySensor::begin() {
    Wire.begin();
    Serial.begin(9600); // Ensure Serial communication is initialized

    if (!init()) {
        Serial.println("AHT21 Initialization Failed!");
        delay(5000); // Prevent system from freezing indefinitely
        return;
    }
    Serial.println("AHT21 Initialized.");
}

bool TemperatureHumiditySensor::init() {
    Wire.beginTransmission(AHT21_ADDRESS);
    Wire.write(0x71);  // Status command
    if (Wire.endTransmission() != 0) { // Check if transmission was successful
        Serial.println("Failed to communicate with AHT21.");
        return false;
    }

    Wire.requestFrom(AHT21_ADDRESS, 1);
    if (Wire.available()) {
        uint8_t status = Wire.read();
        Serial.print("AHT21 Status: ");
        Serial.println(status, HEX);
        return (status & 0x08);  // Check if sensor is calibrated
    }

    Serial.println("Failed to request data from AHT21.");
    return false;
}

bool TemperatureHumiditySensor::read(float &temperature, float &humidity) {
    Wire.beginTransmission(AHT21_ADDRESS);
    Wire.write(0xAC);  // Trigger measurement
    Wire.write(0x33);
    Wire.write(0x00);
    if (Wire.endTransmission() != 0) {
        Serial.println("Failed to trigger measurement.");
        return false;
    }

    delay(80);  // Wait for measurement

    Wire.requestFrom(AHT21_ADDRESS, 6);
    if (Wire.available() < 6) {
        Serial.println("Insufficient data received from AHT21.");
        return false;
    }

    uint8_t data[6];
    for (int i = 0; i < 6; i++) {
        data[i] = Wire.read();
    }

    if ((data[0] & 0x80) != 0) {
        Serial.println("Invalid data from AHT21.");
        return false;
    }

    uint32_t rawHumidity = ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];
    rawHumidity >>= 4;
    humidity = (rawHumidity * 100.0) / 1048576.0;

    uint32_t rawTemperature = ((uint32_t)(data[3] & 0x0F) << 16) | ((uint32_t)data[4] << 8) | data[5];
    temperature = ((rawTemperature * 200.0) / 1048576.0) - 50;

    return true;
}
