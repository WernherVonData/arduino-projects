#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BMP085.h>

namespace
{
  Adafruit_BMP085 bmp;
}

void setup()
{
  Serial.begin(9600);
  if (!bmp.begin())
  {
    Serial.println("Could not find valid BMP sensor");
    while (1)
    {
    }
  }
}

void loop()
{
  float temp = bmp.readTemperature();
  Serial.print("Temperature ");
  Serial.print(temp);
  Serial.println(" *C");

  float pressure = static_cast<float>(bmp.readPressure()) / 100.0f;
  Serial.print("Pressure ");
  Serial.print(pressure);
  Serial.println(" Pa");
  Serial.println("*****");

  delay(1000);
}
