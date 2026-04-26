#include <BleGamepad.h>

BleGamepad bleGamepad("GamePad", "DIY-Hardware", 100);

// Updated Pin Definitions
const int potX = 36; // Changed to GPIO 36 (ADC1) for BT compatibility
const int potY = 35; 
const int ledPins[] = {32, 26, 33, 4}; // LED 1 is now on Pin 32
const int buttonPins[] = {13, 12, 14, 27};
const int numOfButtons = 4;

void setup() {
  Serial.begin(115200);
  
  for(int i=0; i < numOfButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }
  
  bleGamepad.begin();
}

void loop() {
  if (bleGamepad.isConnected()) {
    // Read Joystick
    int xVal = analogRead(potX);
    int yVal = analogRead(potY);

    // Map and send to Bluetooth
    bleGamepad.setLeftThumb(map(xVal, 0, 4095, 0, 32737), 
                           map(yVal, 0, 4095, 0, 32737));

    // Button Logic
    for (int i = 0; i < numOfButtons; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        bleGamepad.press(BUTTON_1 + i);
        digitalWrite(ledPins[i], HIGH);
      } else {
        bleGamepad.release(BUTTON_1 + i);
        digitalWrite(ledPins[i], LOW);
      }
    }
    bleGamepad.sendReport();
  }
  delay(10);
}