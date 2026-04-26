#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// -------- WiFi --------
#define WIFI_SSID "YOUR SSID"
#define WIFI_PASS "YOUR PASSWORD"

// -------- Adafruit IO --------
#define AIO_SERVER     "io.adafruit.com"
#define AIO_PORT       1883
#define AIO_USERNAME   "YOUR USERNAME"
#define AIO_KEY        "YOUR API KEY"

// -------- Pins --------
const int VIB_PIN = 14;
const int BUTTON_PIN = 27;
const int RED_LED = 13;
const int GREEN_LED = 12;

// -------- Timing --------
unsigned long lastKnockTime = 0;
int knockCount = 0;
const int secretKnockDelay = 500;
const int tolerance = 100;
const int totalKnocksNeeded = 3;

// -------- LCD --------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- MQTT --------
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_PORT,
                          AIO_USERNAME, AIO_KEY);

// Feeds
Adafruit_MQTT_Publish feedKnock =
  Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/knock-count");

Adafruit_MQTT_Publish feedStatus =
  Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/lock-status");

// -------- MQTT CONNECT --------
void mqtt_connect() {
  while (!mqtt.connected()) {
    if (mqtt.connect() == 0) {
      Serial.println("MQTT Connected");
    } else {
      Serial.println("MQTT Retry...");
      delay(3000);
    }
  }
}

// -------- SETUP --------
void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  pinMode(VIB_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // WiFi connect
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  mqtt_connect();
  resetLock();
}

// -------- LOOP --------
void loop() {
  mqtt_connect();

  int sensorState = digitalRead(VIB_PIN);

  if (sensorState == HIGH) {
    handleKnock();
    delay(150);
  }

  // Timeout reset
  if (knockCount > 0 && (millis() - lastKnockTime > 3000)) {
    Serial.println("Sequence Timeout");
    resetLock();
  }
}

// -------- HANDLE KNOCK --------
void handleKnock() {
  unsigned long currentTime = millis();

  if (knockCount == 0) {
    knockCount = 1;
    lastKnockTime = currentTime;

    Serial.println("First Knock");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Knock 1");

    feedKnock.publish((float)knockCount);   // 🔥 IoT push
    return;
  }

  unsigned long gap = currentTime - lastKnockTime;

  if (abs(gap - secretKnockDelay) <= tolerance) {
    knockCount++;
    lastKnockTime = currentTime;

    Serial.print("Knock ");
    Serial.println(knockCount);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Knock ");
    lcd.print(knockCount);

    feedKnock.publish((float)knockCount);   // 🔥 IoT push

    if (knockCount == totalKnocksNeeded) {
      unlock();
    }

  } else {
    Serial.println("Wrong Timing");
    resetLock();
  }
}

// -------- UNLOCK --------
void unlock() {
  Serial.println("Unlocked!");

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Unlocked!");

  feedStatus.publish("UNLOCKED");   // 🔥 IoT push

  delay(3000);
  resetLock();
}

// -------- RESET --------
void resetLock() {
  knockCount = 0;

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Locked");

  feedStatus.publish("LOCKED");   // 🔥 IoT push
}