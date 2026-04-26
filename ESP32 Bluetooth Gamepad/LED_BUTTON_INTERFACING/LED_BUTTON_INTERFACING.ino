// Button pins
int buttonPins[] = {13, 12, 14, 27};

// LED pins
int ledPins[] = {32, 26, 33, 4};

int num = 4;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < num; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // button
    pinMode(ledPins[i], OUTPUT);          // LED
  }
}

void loop() {
  for (int i = 0; i < num; i++) {

    int state = digitalRead(buttonPins[i]);

    if (state == LOW) {   // button pressed
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }

  }

  delay(50);
}