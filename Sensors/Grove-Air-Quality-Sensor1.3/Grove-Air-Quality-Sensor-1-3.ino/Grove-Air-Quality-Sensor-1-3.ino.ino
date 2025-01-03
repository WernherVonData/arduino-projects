#include "Air_Quality_Sensor.h"

AirQualitySensor sensor(A0);

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Waiting for sensor to init...");
  delay(20000);
  if (sensor.init()) {
    Serial.println("Sensor ready.");
  } else {
    Serial.println("Sensor error.");
  }
}

void loop() {
  int quality = sensor.slope();
  Serial.print("Sensor quality: ");
  Serial.print(quality);
  Serial.print(", value: ");
  Serial.println(sensor.getValue());
  if (quality == AirQualitySensor::FORCE_SIGNAL) {
    Serial.println("High pollution! Force signal active.");
  } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
    Serial.println("High pollution!");
  } else if (quality == AirQualitySensor::LOW_POLLUTION) {
    Serial.println("Low pollution!");
  } else if (quality == AirQualitySensor::FRESH_AIR) {
    Serial.println("Fresh air.");
  }
  delay(1000);
}
