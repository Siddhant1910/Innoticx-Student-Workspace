#include <WiFi.h>
#include "AdafruitIO_WiFi.h"

// Credentials
#define IO_USERNAME "your_username"
#define IO_KEY "your_aio_key"

#define WIFI_SSID "your_wifi"
#define WIFI_PASS "your_password"

// Pins
const int trigPin = 19;
const int echoPin = 18;
const int RELAY_PIN = 26;
const int LED_PIN = 2;
const int BUZZER_PIN = 4;

// Adafruit IO
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// Feeds
AdafruitIO_Feed *distanceFeed = io.feed("distance");
AdafruitIO_Feed *statusFeed = io.feed("status");
AdafruitIO_Feed *pumpFeed = io.feed("pump");

// Manual control
bool manualPump = false;

// Callback (dashboard control)
void handlePump(AdafruitIO_Data *data) {
  manualPump = data->toInt();
  digitalWrite(RELAY_PIN, manualPump ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Connect to Adafruit
  io.connect();

  pumpFeed->onMessage(handlePump);

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to Adafruit IO");

  pumpFeed->get();
}

void loop() {
  io.run();

  // Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Send to cloud
  distanceFeed->save(distance);

  // Auto logic (only if manual OFF)
  if (!manualPump) {

    if (distance > 20) {
      Serial.println("LOW - Pump ON");
      statusFeed->save("LOW");

      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
    }
    else if (distance > 10) {
      Serial.println("MEDIUM");
      statusFeed->save("MEDIUM");

      digitalWrite(BUZZER_PIN, LOW);
    }
    else {
      Serial.println("FULL - Pump OFF");
      statusFeed->save("FULL");

      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);
    }
  }

  delay(3000);
}
