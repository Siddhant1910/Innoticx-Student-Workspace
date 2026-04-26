const int VIB_PIN = 14; 

void setup() {
  Serial.begin(115200);
  pinMode(VIB_PIN, INPUT);
  Serial.println("Vibration Sensor Ready. Tap the sensor!");
}

void loop() {
  int measurement = digitalRead(VIB_PIN);
  if (measurement == HIGH) {
    Serial.println("Vibration Detected!");
    delay(100); // Simple debounce
  }
}