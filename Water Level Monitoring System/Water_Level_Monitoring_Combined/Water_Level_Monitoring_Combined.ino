const int trigPin = 19;
const int echoPin = 18;
const int RELAY_PIN = 26;
const int LED_PIN = 2;
const int BUZZER_PIN = 4;

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Ultrasonic reading
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Logic
  if (distance > 20) {
    // LOW WATER
    Serial.println("LOW - Pump ON");
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
  }
  else if (distance > 10) {
    // MEDIUM
    Serial.println("MEDIUM");
    digitalWrite(BUZZER_PIN, LOW);
  }
  else {
    // FULL
    Serial.println("FULL - Pump OFF");
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
  }

  delay(1000);
}
