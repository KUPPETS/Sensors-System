#ifndef MENULCD_H
#define MENULCD_H

#include <Arduino.h>
#include "LCDClass.h"
#include "JoyStickClass.h"

// Menu items
extern const char* menuItems[];
extern const int menuSize;
extern int currentMenuItem;

// Function prototypes
void handleNavigation(JoyStick &joystick);
void displayMenu(LCDClass &lcd);

#endif