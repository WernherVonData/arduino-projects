#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

struct HeartData
{
  HeartData(short offset, short length) : offset(offset), length(length) {}
  short offset;
  short length;
};

constexpr int WIDTH = 84;
constexpr int HEIGHT = 48;
constexpr int HEART_DATA_SIZE = 43;

const unsigned char PROGMEM z_uml[] = {
    B00100000,
    B00000000,
    B11111000,
    B00010000,
    B00100000,
    B01000000,
    B11111000,
    B00000000,
};

const unsigned char PROGMEM e_uml[] = {
    B00000000,
    B00000000,
    B01110000,
    B10001000,
    B11111000,
    B10000000,
    B01110000,
    B00100000,
};

const unsigned char PROGMEM c_acute[] = {
    B00010000,
    B00100000,
    B01110000,
    B10001000,
    B10000000,
    B10001000,
    B01110000,
    B00000000,
};

const unsigned char PROGMEM l_acute[] = {
    B00110000,
    B00010000,
    B00011000,
    B00110000,
    B00010000,
    B00010000,
    B00111000,
    B00000000,
};

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

void resetDisplay(int text_size)
{
  display.clearDisplay();
  display.setTextSize(text_size);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
}

void updateDisplay(int delay_time)
{
  display.display();
  delay(delay_time);
}

void loop()
{
  resetDisplay(2);
  display.println("Kochana");
  display.println("Eluniu!");
  updateDisplay(5000);

  resetDisplay(1);
  display.println("Ostatnie 5 lat");
  display.println("");
  display.print("By");
  display.drawBitmap(display.getCursorX(), display.getCursorY(), l_acute, 8, 8, BLACK);
  display.setCursor(display.getCursorX() + 7, display.getCursorY());
  display.print("o");
  display.setCursor(0, display.getCursorY() + 8);
  display.println("najlepszym...");
  updateDisplay(5000);

  resetDisplay(1);
  display.println("Okresem");
  display.println("");
  display.print("Mojego ");
  display.drawBitmap(display.getCursorX(), display.getCursorY(), z_uml, 8, 8, BLACK);
  display.setCursor(display.getCursorX() + 7, display.getCursorY());
  display.print("ycia");
  updateDisplay(5000);

  resetDisplay(1);
  display.println("Kocham Ciebie");
  display.println("");
  display.print("i Kasi");
  display.drawBitmap(display.getCursorX(), display.getCursorY(), e_uml, 8, 8, BLACK);
  updateDisplay(5000);

  resetDisplay(2);
  display.println("Bardzo");
  display.println("Mocno!");
  updateDisplay(5000);

  resetDisplay(1);
  display.print("I chc");
  display.drawBitmap(display.getCursorX(), display.getCursorY(), e_uml, 8, 8, BLACK);
  display.setCursor(display.getCursorX() + 10, display.getCursorY());
  display.println("zawsze");
  display.println("");
  display.print("by");
  display.drawBitmap(display.getCursorX(), display.getCursorY(), c_acute, 8, 8, BLACK);
  display.setCursor(display.getCursorX() + 10, display.getCursorY());
  display.print("z Wami");
  updateDisplay(5000);

  resetDisplay(1);
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
  updateDisplay(10000);
}
