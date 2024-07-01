#include <Arduino.h>
#include <SPI.h>

#include <Adafruit_BMP085.h>
#include <DHT.h>

#define DHT11_PIN 2
#define CS_PIN 10

#define HUMIDITY_LINE 0x02
#define TEMPERATURE_LINE 0x04
#define TEMPERATURE_LINE_2 0x05

#define PRESSURE_LINE 0x07
#define PRESSURE_LINE_2 0x08
#define STANDARD_ATM 1013

namespace
{
DHT dht11(DHT11_PIN, DHT11);
Adafruit_BMP085 bmp;
}


void setup()
{
  pinMode(CS_PIN, OUTPUT);
  SPI.begin();
  sendData(0x0C, 0x00); // Shutdown: 1 (normal operation)
  delay(2000);
  sendData(0x09, 0x00); // Decode mode: none
  sendData(0x0A, 0x0F); // Intensity: 3 (0x00 to 0x0F)
  sendData(0x0B, 0x07); // Scan limit: 7 (all digits)
  sendData(0x0C, 0x01); // Shutdown: 1 (normal operation)
  Serial.begin(9600);
  dht11.begin();

  if (!bmp.begin())
  {
    Serial.println("Could not find valid BMP sensor");
    while (1)
    {
    }
  }
  for (byte i = 1; i <= 8; ++i) {
    sendData(i, 0x00);
  }
  delay(2000);
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
    float temperature = (dht_temp + bmp_temp) / 2.0;
    Serial.print(temperature);
    Serial.println("°C");
    Serial.print("Pressure ");
    Serial.print(bmp_pressure);
    Serial.println(" hPa");
    Serial.println("*****");
    sendData(HUMIDITY_LINE, (byte)dht_humidity);
    sendData(TEMPERATURE_LINE, (byte)temperature);
    sendData(TEMPERATURE_LINE_2, (byte)getTwoDecimals(temperature));
    float pressure_diff = STANDARD_ATM - (int)(bmp_pressure);
    sendData(PRESSURE_LINE, (byte)pressure_diff);
    delay(1000);
  }
}

void sendData(byte register_address, byte value) {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(register_address);
  SPI.transfer(value);
  digitalWrite(CS_PIN, HIGH);
}

int getTwoDecimals(float value_to_change) {
  int value = (value_to_change - (int) value_to_change) * 100;
  return (value / 10 % 10 * 10) + (value % 10);
}
