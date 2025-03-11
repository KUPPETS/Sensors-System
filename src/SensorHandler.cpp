#include "SensorHandler.h"
#include <Arduino.h>

void handleSensorReadings(int currentMenuItem, LCDClass &lcd, TemperatureHumiditySensor &tempHumiditySensor, MoistureSensor &moistureSensor, FluidSensor &fluidSensor) {
    switch (currentMenuItem) {
        case 0: { // Temperature
            float temperature, humidity;
            if (tempHumiditySensor.read(temperature, humidity)) {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Temp: ");
                lcd.print(temperature);
                lcd.print(" C");
            } else {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Error reading");
                lcd.setCursor(0, 1);
                lcd.print("temperature!");
            }
            break;
        }
        case 1: { // Humidity
            float temperature, humidity;
            if (tempHumiditySensor.read(temperature, humidity)) {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Humidity: ");
                lcd.print(humidity);
                lcd.print(" %");
            } else {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Error reading");
                lcd.setCursor(0, 1);
                lcd.print("humidity!");
            }
            break;
        }
        case 2: { // Moisture
            int moisture = moistureSensor.readValue();
            if (moisture >= 0) {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Moisture: ");
                lcd.print(moisture);
            } else {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Error reading");
                lcd.setCursor(0, 1);
                lcd.print("moisture!");
            }
            break;
        }
        case 3: { // Fluid Level
            int fluidLevel = fluidSensor.readValue();
            if (fluidLevel >= 0) {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Fluid Level: ");
                lcd.print(fluidLevel);
            } else {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Error reading");
                lcd.setCursor(0, 1);
                lcd.print("fluid level!");
            }
            break;
        }
        case 4: { // Exit
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Returning to");
            lcd.setCursor(0, 1);
            lcd.print("Main Menu...");
            delay(2000);
            return;
        }
    }

    delay(2000);
}