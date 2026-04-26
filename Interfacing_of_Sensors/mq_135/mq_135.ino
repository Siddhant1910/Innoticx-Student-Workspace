const int MQ135_PIN = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int airQuality = analogRead(MQ135_PIN);
  Serial.println(airQuality);

  if (airQuality > 1000) {
    Serial.println("Poor Air Quality");
  }
}
