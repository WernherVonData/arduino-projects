#ifndef LCD_PRINT_HPP
#define LCD_PRINT_HPP

#include <LiquidCrystal.h>

class LCDPrinter {

public:
LCDPrinter(const int rs, const int enable, const int db4, const int db5, const int db6, const int db7);
void print(const String& text);

private:
LiquidCrystal lcd;
};

#endif