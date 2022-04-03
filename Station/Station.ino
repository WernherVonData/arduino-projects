#include "lcd_print.hpp"

LCDPrinter lcd(2,3,4,5,6,7);

const int sensor_pin = A0;
const float max_pin_voltage = 1.1; // defined by the analogReference()
const float analog_size = 1024.0; // analog reads on 10 bits of information
const float offset_voltage = 0.5;

int iterator = 0;
const int loop_max = 100;
float current_temperature = 0;
float temp_temperature = 0;

float readTemperature() {
  int temperature_voltage = analogRead(sensor_pin);
  float real_voltage = (temperature_voltage/analog_size) * max_pin_voltage;
  return (real_voltage - offset_voltage) * 100.0;
}

void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
  delay(100);
  current_temperature = readTemperature();
}

void loop() {
  Serial.println(iterator);
  if (iterator == loop_max){
    current_temperature = temp_temperature/(float)loop_max;
    temp_temperature = 0;
    iterator = 0;
  } else {
    temp_temperature += readTemperature();
  }

  lcd.print(String(current_temperature)+"*C");
  iterator += 1;
  delay(100);
}