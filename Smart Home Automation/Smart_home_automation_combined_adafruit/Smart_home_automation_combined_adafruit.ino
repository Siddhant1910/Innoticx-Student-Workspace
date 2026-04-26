#include <WiFi.h>
#include "AdafruitIO_WiFi.h"

// Adafruit IO credentials
#define IO_USERNAME "your_username"
#define IO_KEY "your_aio_key"

// WiFi
#define WIFI_SSID "your_wifi"
#define WIFI_PASS "your_password"

// Pins
const int PIR_PIN = 14;
const int LDR_PIN = 34;
const int RELAY_PIN = 26;

// Adafruit IO
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// Feeds
AdafruitIO_Feed *motionFeed = io.feed("motion");
AdafruitIO_Feed *lightFeed = io.feed("light");
AdafruitIO_Feed *relayFeed = io.feed("relay");

// Variables
bool manualRelay = false;

// Callback (when button pressed on dashboard)
void handleRelay(AdafruitIO_Data *data) {
  manualRelay = data->toInt();
  digitalWrite(RELAY_PIN, manualRelay ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Connect to Adafruit IO
  io.connect();

  // Attach callback
  relayFeed->onMessage(handleRelay);

  // Wait for connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to Adafruit IO");

  relayFeed->get(); // get last value
}

void loop() {
  io.run();

  int motion = digitalRead(PIR_PIN);
  int light = analogRead(LDR_PIN);

  // Send data to dashboard
  motionFeed->save(motion);
  lightFeed->save(light);

  // Auto control (only if manual OFF)
  if (!manualRelay) {
    if (motion == HIGH && light < 500) {
      digitalWrite(RELAY_PIN, HIGH);
    } else {
      digitalWrite(RELAY_PIN, LOW);
    }
  }

  delay(2000);
}
