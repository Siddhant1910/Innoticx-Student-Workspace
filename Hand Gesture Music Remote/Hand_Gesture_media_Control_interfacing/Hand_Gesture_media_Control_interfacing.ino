#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Magic-Music", "DIY-Hardware", 100);

// Sensor 1 (Play/Pause)
const int trig1 = 5;
const int echo1 = 18;
// Sensor 2 (Skip)
const int trig2 = 19;
const int echo2 = 21;

const int ledPlay = 32;
const int ledSkip = 33;

// Detection Threshold (cm)
const int threshold = 15;

int getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH, 30000); // 30ms timeout
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);
  pinMode(trig1, OUTPUT); pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT); pinMode(echo2, INPUT);
  pinMode(ledPlay, OUTPUT); pinMode(ledSkip, OUTPUT);
  
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    int dist1 = getDistance(trig1, echo1);
    int dist2 = getDistance(trig2, echo2);

    // Sensor 1: Play/Pause Logic
    if (dist1 > 0 && dist1 < threshold)