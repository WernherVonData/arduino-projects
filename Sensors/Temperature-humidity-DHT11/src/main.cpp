#include <Arduino.h>
#include <DHT.h>

#define DHT11_PIN 2

DHT dht11(DHT11_PIN, DHT11);

void setup()
{
  Serial.begin(9600);
  dht11.begin();
}

void loop()
{
  delay(2000);
  float humidity = dht11.readHumidity();
  float temperature = dht11.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("Failed to read from sensor");
  }
  else
  {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
    Serial.println("*****");
  }
}
