#include <Arduino.h>
#include <SPI.h>

#include <Adafruit_BMP085.h>
#include <DHT.h>

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#define DHT11_PIN 2
#define LED_PIN 8

namespace
{
DHT dht11(DHT11_PIN, DHT11);
Adafruit_BMP085 bmp;
Adafruit_PCD8544 display{7, 6, 5, 4, 3};
}


void setup()
{
  Serial.begin(9600);
  dht11.begin();

  if (!bmp.begin())
  {
    Serial.println("Could not find valid BMP sensor");
    while (1)
    {
    }
  }
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

void loop()
{
  delay(2000);
  float dht_humidity = dht11.readHumidity();
  float dht_temp = dht11.readTemperature();
  float bmp_temp = bmp.readTemperature();
  float bmp_pressure = static_cast<float>(bmp.readPressure()) / 100.0f;

  if (isnan(dht_humidity) || isnan(dht_temp))
  {
    Serial.println("Failed to read from sensor");
  }
  else
  {
    Serial.print("Humidity: ");
    Serial.print(dht_humidity);
    Serial.println("%");
    Serial.print("Temperature: ");
    Serial.print((dht_temp + bmp_temp) / 2.0);
    Serial.println("°C");
    Serial.print("Pressure ");
    Serial.print(bmp_pressure);
    Serial.println(" hPa");
    Serial.println("*****");
  }
}
