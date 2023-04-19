#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Fonts/Org_01.h>

Adafruit_PCD8544 display{7, 6, 5, 4, 3};

constexpr int WIDTH = 84;
constexpr int HEIGHT = 48;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing...");
  display.begin();
  display.setContrast(60);
  display.clearDisplay();
  display.display();
}

void loop()
{
  display.clearDisplay();
  display.setTextColor(BLACK);

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("Kochana");
  display.println("Eluniu!");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Ostatnie 5 lat");
  display.println("");
  display.println("Bylo");
  display.println("najlepszym...");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Okresem");
  display.println("");
  display.println("Mojego zycia");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Kocham Ciebie");
  display.println("");
  display.println("i Kasie");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("Bardzo");
  display.println("Mocno!");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("I chce zawsze");
  display.println("");
  display.println("byc z Toba");
  display.display();
  delay(5000);
}
