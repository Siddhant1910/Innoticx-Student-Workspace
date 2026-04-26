#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pins
const int VIB_PIN = 14;
const int BUTTON_PIN = 27;
const int RED_LED = 13;
const int GREEN_LED = 12;

// Timing Variables
unsigned long lastKnockTime = 0;
int knockCount = 0;
const int secretKnockDelay = 500; // Expected gap between knocks in ms
const int tolerance = 100;        // +/- 100ms margin
const int totalKnocksNeeded = 3;  // e.g., "Tap...Tap...Tap"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  
  pinMode(VIB_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  resetLock();
}

void loop() {
  int sensorState = digitalRead(VIB_PIN);
  
  if (sensorState == HIGH) {
    handleKnock();
    delay(150); // Debounce vibration
  }

  // Reset progress if too much time passes (3 seconds)
  if (knockCount > 0 && (millis() - lastKnockTime > 3000)) {
    Serial.println("Sequence Timeout");
    resetLock();
  }
}

void handleKnock()