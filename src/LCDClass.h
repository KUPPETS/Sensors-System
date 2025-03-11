#ifndef LCDCLASS_H
#define LCDCLASS_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LCDClass {
public:
    LCDClass(int i2c_addr, int en, int rw, int rs, int d4, int d5, int d6, int d7, int bl);
    void begin();
    void displayMessage(const char* message, int row);
    void flashBacklight(int times);
    void scrollDemo();

    void clear();
    void setCursor(int col, int row);
    void print(const char* text);
    void print(int value);

private:
    LiquidCrystal_I2C lcd;
};

#endif