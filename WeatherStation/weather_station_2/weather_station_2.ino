#include <Arduino.h>
#include <SPI.h>

// Grove Air Quality Sensor
#include <Air_Quality_Sensor.h>

// Temperature and air pressure sensor
#include <Adafruit_BMP085.h>

// DHT Temperature and humidity sensor
#include <DHT.h>

// Nokia screen
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

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
  
const constexpr int WIDTH = 84;
const constexpr int HEIGHT = 48;
const constexpr int dht11_pin = 2;
DHT dht11(dht11_pin, DHT11);
Adafruit_BMP085 bmp;
AirQualitySensor sensor(A0);
Adafruit_PCD8544 display{7, 6, 5, 4, 3};
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

void setup()
{
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Waiting for air sensor to init...");
  delay(20000);
  if (sensor.init()) {
    Serial.println("Sensor ready.");
  } else {
    Serial.println("Sensor error.");
  }
  dht11.begin();

  if (!bmp.begin())
  {
    Serial.println("Could not find valid BMP sensor");
    while (1)
    {
    }
  }
  Serial.println("Initializing screen");
  display.begin();
  display.setContrast(30);
  display.clearDisplay();
  display.display();
  delay(2000);
}

String getAirInfo(int quality) {
  if (quality == AirQualitySensor::FORCE_SIGNAL) {
    return "High pollution! Force signal active.";
  } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
    return "High pollution!";
  } else if (quality == AirQualitySensor::LOW_POLLUTION) {
    return "Low pollution!";
  } else if (quality == AirQualitySensor::FRESH_AIR) {
    return "Fresh air.";
  }
  return "Uknown air quality!!!";
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
  
    String air_info = getAirInfo(sensor.slope());
    Serial.println(air_info);
    Serial.println("*****");
  
    resetDisplay(1);
    display.println(String(temperature) + " celsius");
    display.println(String(dht_humidity) + "%");
    display.println(String(bmp_pressure) + "hPa");
    display.println();
    display.println(air_info + " " + String(sensor.getValue()));
    updateDisplay(60000);
  }
}
