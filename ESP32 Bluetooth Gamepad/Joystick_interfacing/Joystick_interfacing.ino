
int xPin = 36;
int yPin = 35;
int buttonPin = 32;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int button = digitalRead(buttonPin);

  // Direction logic
  if (x < 1500) {
    Serial.println("LEFT");
  }
  else if (x > 3000) {
    Serial.println("RIGHT");
  }
  else if (y < 1500) {
    Serial.println("DOWN");
  }
  else if (y > 3000) {
    Serial.println("UP");
  }
  else {
    Serial.println("CENTER");
  }

  // Button check
  if (button == LOW) {
    Serial.println("BUTTON PRESSED");
  }

  delay(300);
}