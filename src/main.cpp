#include <Arduino.h>
#include "JoyStickClass.h"
#include "LCDClass.h"
#include "FluidSensor.h"
#include "TemperatureHumiditySensor.h"
#include "MoistureSensor.h"
#include "SensorHandler.h"
#include "MenuLCD.h"

// Initialize objects with correct pins
JoyStick joystick(A0, A1, 2);
LCDClass lcd(0x27, 2, 255, 0, 4, 5, 6, 7, 3);
FluidSensor fluidSensor(5);
TemperatureHumiditySensor tempHumiditySensor;
MoistureSensor moistureSensor(A2);

void setup() {
    Serial.begin(9600);
    joystick.begin();
    lcd.begin();
    fluidSensor.begin();
    tempHumiditySensor.begin();
    moistureSensor.begin();

    // Initial LCD messages
    lcd.displayMessage("Hello world!", 0);
    delay(1000);
    lcd.displayMessage("How are you?", 1);
    delay(8000);

}

void loop() {
    // Handle menu navigation
    handleNavigation(joystick);

    // Display the current menu
    displayMenu(lcd);

    // Check if the joystick button is pressed
    if (joystick.getButtonState() == LOW) { // Button pressed
        // Call the handleSensorReadings function from SensorHandler.cpp
        handleSensorReadings(currentMenuItem, lcd, tempHumiditySensor, moistureSensor, fluidSensor);
        delay(2000); // Display sensor readings for 2 seconds
    }

    delay(100); // Small delay to reduce CPU usage
}