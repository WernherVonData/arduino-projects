#include <Arduino.h>

int analog_pin = A0;
int digital_pin = 3;

void setup()
{
  pinMode(analog_pin, INPUT);
  pinMode(digital_pin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  float analog_value;
  int digital_value;

  analog_value = analogRead(analog_pin) * (5.0 / 1023.0);
  digital_value = digitalRead(digital_pin);

  Serial.print("Analog: ");
  Serial.print(analog_value, 4);
  Serial.println("V");
  if (digital_value == 1)
  {
    Serial.println("Extreme value reached");
  }
  else
  {
    Serial.println("Extreme value not reached yet");
  }
  delay(500);
}
