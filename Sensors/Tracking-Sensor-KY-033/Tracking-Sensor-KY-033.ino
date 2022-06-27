#include "lcd_print.hpp"

const int tracking_pin = 10;

LCDPrinter lcd(2,3,4,5,6,7);

void setup() {
  pinMode(tracking_pin, INPUT);
}

void loop() {
  bool signal = digitalRead(tracking_pin);

  if (signal == HIGH) {
    lcd.print("On line");
  } else {
    lcd.print("Not on line");
  }
  delay(500);
}