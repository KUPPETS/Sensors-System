#include "LCDClass.h"

LCDClass::LCDClass(int i2c_addr, int en, int rw, int rs, int d4, int d5, int d6, int d7, int bl)
    : lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE) {}

void LCDClass::begin() {
    lcd.begin(16, 2);
}

void LCDClass::displayMessage(const char* message, int row) {
    lcd.setCursor(0, row);
    lcd.print(message);
}

void LCDClass::flashBacklight(int times) {
    for (int i = 0; i < times; i++) {
        lcd.backlight();
        delay(250);
        lcd.noBacklight();
        delay(250);
    }
    lcd.backlight();
}

void LCDClass::scrollDemo() {
    lcd.setCursor(0, 0);
    lcd.print("Scroll demo - ");
    delay(1500);
    lcd.autoscroll();
    for (int thisChar = 0; thisChar < 10; thisChar++) {
        lcd.print(thisChar);
        delay(500);
    }
    lcd.noAutoscroll();
    lcd.clear();
    delay(1000);
}

void LCDClass::clear() {
    lcd.clear();
}

void LCDClass::setCursor(int col, int row) {
    lcd.setCursor(col, row);
}

void LCDClass::print(const char* text) {
    lcd.print(text);
}

void LCDClass::print(int value) {
    lcd.print(value);
}