#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display{7, 6, 5, 4, 3};

constexpr int WIDTH = 84;
constexpr int HEIGHT = 48;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing...");
  display.begin();
  display.setContrast(60);
  display.display();
  delay(100);
  display.clearDisplay();
  display.display();
}

void loop()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  // display.println("Kochana");
  // display.println("Eluniu!");
  display.println("Good");
  display.println("Night!");
  display.display();
  delay(2000);
}