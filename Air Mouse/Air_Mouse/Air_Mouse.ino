#include <Wire.h>
#include <BleMouse.h>

BleMouse bleMouse("ESP32 Mouse", "DIY", 100);

const int BUTTON_PIN = 23;

int16_t ax, ay;

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Start BLE mouse
  bleMouse.begin();

  // Wake MPU6050
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  if (bleMouse.isConnected()) {

    // Read MPU6050
    Wire.beginTransmission(0x68);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(0x68, 6, true);

    ax = Wire.read() << 8 | Wire.read();
    ay = Wire.read() << 8 | Wire.read();

    // Scale movement (adjust sensitivity)
    int moveX = ay / 2000;  // left/right
    int moveY = ax / 2000;  // up/down

    // Move mouse
    bleMouse.move(moveX, moveY);

    // Button click
    if (digitalRead(BUTTON_PIN) == LOW) {
      bleMouse.click(MOUSE_LEFT);
      delay(200); // debounce
    }

    delay(20);
  }
}