Arduino Plant Monitoring System
🌿 A smart monitoring system for plants with sensor data display, joystick navigation, and automated lighting control.

Key Features
Multi-sensor integration:

🌡️ Temperature & Humidity (DHT11/DHT22)

💧 Soil Moisture (Analog capacitive sensor)

🚰 Fluid Level (Analog sensor for hydroponics)

Interactive LCD Menu:

Navigate sensor readings with a joystick (up/down/button).

Display data on a 16x2 I2C LCD.

Automated Lighting:

Configurable schedules (18/6 or 12/12) saved to EEPROM.

Calculates lamp on/off times based on UTC.

Hardware
Arduino Uno/Mega

Joystick module (X/Y analog + button)

I2C LCD (16x2)

DHT11/DHT22, Capacitive Moisture Sensor, Fluid Sensor

Code Structure
Modular C++ Classes:

JoyStick (navigation input)

LCDClass (menu/output display)

FluidSensor/MoistureSensor/TemperatureHumiditySensor (data collection)

LightScheduleManager (EEPROM-backed lighting logic)

Setup
Clone the repo:

bash
git clone https://github.com/yourusername/arduino-plant-monitor.git  
Upload to Arduino IDE (requires LiquidCrystal_I2C, DHT libraries).

Connect sensors to pins defined in main.cpp.

Demo
GIF showing joystick menu navigation and sensor readings (Optional: Add a screenshot/video later!)

License
MIT License — free for personal and educational use.
