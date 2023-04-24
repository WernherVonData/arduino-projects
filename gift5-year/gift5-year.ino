#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Fonts/Org_01.h>

struct HeartData
{
  HeartData(short offset, short length) : offset(offset), length(length) {}
  short offset;
  short length;
};

constexpr int WIDTH = 84;
constexpr int HEIGHT = 48;
constexpr int HEART_DATA_SIZE = 43;

const HeartData HEART_DATA[] = {
    {5, 6},
    {4, 9},
    {3, 11},
    {2, 13},
    {1, 15},
    {0, 17},
    {0, 18},
    {0, 18},
    {0, 19},
    {0, 19},
    {0, 19},
    {0, 20},
    {0, 20},
    {0, 20},
    {0, 20},
    {0, 20},
    {0, 19},
    {0, 19},
    {0, 19},
    {0, 19},
    {0, 18},
    {0, 18},
    {0, 17},
    {0, 17},
    {0, 16},
    {0, 15},
    {0, 14},
    {0, 13},
    {0, 12},
    {0, 11},
    {0, 10},
    {0, 9},
    {0, 8},
    {0, 7},
    {0, 6},
    {0, 5},
    {0, 4},
    {0, 3},
    {0, 2},
    {0, 2},
    {0, 1},
    {0, 1},
    {0, 1}};

Adafruit_PCD8544 display{7, 6, 5, 4, 3};

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
  display.println("byc z Wami");
  display.display();
  delay(5000);

  display.clearDisplay();
  short heartY = 4;
  for (int i = 0; i < HEART_DATA_SIZE; ++i)
  {
    for (short x = HEART_DATA[i].offset; x < HEART_DATA[i].offset + HEART_DATA[i].length; ++x)
    {
      display.drawPixel(WIDTH / 2 - x, heartY, BLACK);
      display.drawPixel(WIDTH / 2 + x, heartY, BLACK);
    }
    ++heartY;
  }
  display.display();
  delay(10000);
}
