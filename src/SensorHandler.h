#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <Arduino.h>
#include "LCDClass.h"
#include "TemperatureHumiditySensor.h"
#include "MoistureSensor.h"
#include "FluidSensor.h"

// Function prototype
void handleSensorReadings(int currentMenuItem, LCDClass &lcd, TemperatureHumiditySensor &tempHumiditySensor, MoistureSensor &moistureSensor, FluidSensor &fluidSensor);

#endif