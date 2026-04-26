const int LDR_PIN = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(LDR_PIN);
  Serial.println(value);
}
