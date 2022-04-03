#include "lcd_print.hpp"


LCDPrinter::LCDPrinter(const int rs, const int enable, const int db4, const int db5, const int db6, const int db7)
: lcd(LiquidCrystal(rs, enable, db4, db5, db6, db7))
{
lcd.begin(16,2);
}

void LCDPrinter::print(const String& text) {
  lcd.setCursor(0,0);
  lcd.print(text);
}
