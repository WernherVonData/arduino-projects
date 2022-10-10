const int MOTION_PIN = 7;
const int LED_PIN = 8;

void setup()
{
  pinMode(MOTION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int motion = digitalRead(MOTION_PIN);

  if (motion == HIGH)
  {
    Serial.println("Movement");
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  delay(200);
}