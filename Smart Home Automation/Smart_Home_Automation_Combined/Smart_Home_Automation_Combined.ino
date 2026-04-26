const int PIR_PIN = 14;
const int LDR_PIN = 34;
const int RELAY_PIN = 26;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  int motion = digitalRead(PIR_PIN);
  int light = analogRead(LDR_PIN);

  if (motion == HIGH && light < 500) {
    digitalWrite(RELAY_PIN, HIGH); // Light ON
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Light OFF
  }
}
