#include "MenuLCD.h"
#include "JoyStickClass.h"
#include "LCDClass.h"

// Menu items
const char* menuItems[] = {
    "Temperature",
    "Humidity",
    "Moisture",
    "Fluid Level",
    "Exit"
};
const int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
int currentMenuItem = 0;

// Handle joystick navigation
void handleNavigation(JoyStick &joystick) {
    joystick.readValues();
    int yVal = joystick.getYValue();

    if (yVal > 600) { // Joystick moved up
        currentMenuItem = (currentMenuItem - 1 + menuSize) % menuSize;
    } else if (yVal < 400) { // Joystick moved down
        currentMenuItem = (currentMenuItem + 1) % menuSize;
    }

    delay(200); // Debounce delay
}

// Display the current menu on the LCD
void displayMenu(LCDClass &lcd) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Sensor:");
    lcd.setCursor(0, 1);
    lcd.print(menuItems[currentMenuItem]);
}