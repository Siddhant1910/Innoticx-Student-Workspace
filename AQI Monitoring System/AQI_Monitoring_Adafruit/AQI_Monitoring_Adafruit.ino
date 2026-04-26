#include <WiFi.h>
#include "AdafruitIO_WiFi.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Adafruit IO credentials
#define IO_USERNAME "your_username"
#define IO_KEY "your_aio_key"

// WiFi
#define WIFI_SSID "your_wifi"
#define WIFI_PASS "your_password"

// Sensors
#define DHTPIN 4
#define DHTTYPE DHT11
const int MQ135_PIN = 34;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT
DHT dht(DHTPIN, DHTTYPE);

// Adafruit IO
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// Feeds
AdafruitIO_Feed *tempFeed = io.feed("temperature");
AdafruitIO_Feed *humFeed = io.feed("humidity");
AdafruitIO_Feed *airFeed = io.feed("airquality");

void setup() {
  Serial.begin(115200);

  // I2C (custom pins)
  Wire.begin(26, 25);

  lcd.init();
  lcd.backlight();

  dht.begin();

  // Connect to Adafruit IO
  io.connect();

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to Adafruit IO");
}

void loop() {
  io.run();

  int airQuality = analogRead(MQ135_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Serial Monitor
  Serial.print("Air: ");
  Serial.print(airQuality);
  Serial.print(" Temp: ");
  Serial.print(temp);
  Serial.print(" Hum: ");
  Serial.println(hum);

  // LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air:");
  lcd.print(airQuality);

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print(" H:");
  lcd.print(hum);

  // Send to Adafruit IO
  tempFeed->save(temp);
  humFeed->save(hum);
  airFeed->save(airQuality);

  delay(5000); // send every 5 sec
}
