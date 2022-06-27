#include "lcd_print.hpp"

LCDPrinter lcd(2,3,4,5,6,7);

const int triggeringPin = 11;
const int echoPin = 10;
int duration;
float distance;
float meter;


void setup() {
  Serial.begin(9600);
  pinMode(triggeringPin, OUTPUT);
  digitalWrite(triggeringPin, LOW);
  delayMicroseconds(2);
  pinMode(echoPin, INPUT);
  delay(6000);
  Serial.println("Distance:");
}

void loop() {
  digitalWrite(triggeringPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggeringPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  if (duration >= 38000) {
    Serial.println("Out range");
  } else {
    distance = duration / 58;
    Serial.print(distance);
    Serial.println("cm");
    lcd.print(String(distance) + " cm");
  }
  delay(1000);
}