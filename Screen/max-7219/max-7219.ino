#include <SPI.h>

#define CS_PIN 10

void setup() {
  pinMode(CS_PIN, OUTPUT);
  Serial.begin(9200);
  SPI.begin();
  delay(100);
}

void loop() {
  Serial.println("Display clear");
  clearDisplay();
  delay(200);
  showDisplay();
  delay(500);
}

void clearDisplay() {
  for (byte i = 1; i <= 8; ++i) {
    sendData(i, 0x00);
  }
}

void showDisplay() {
  for (byte i = 1; i <= 8; ++i) {
    sendData(i, i);
  }
}


void sendData(byte register_address, byte value) {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(register_address);
  SPI.transfer(value);
  digitalWrite(CS_PIN, HIGH);
}
