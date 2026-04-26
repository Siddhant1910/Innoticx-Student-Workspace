#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
const int MQ135_PIN = 34;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);
  // Custom I2C pins
  Wire.begin(26, 25);  
  lcd.init();
  lcd.backlight();
  dht.begin();
}
void loop() {
  int airQuality = analogRead(MQ135_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Air: ");
  Serial.print(airQuality);
  Serial.print(" Temp: ");
  Serial.print(temp);
  Serial.print(" Hum: ");
  Serial.println(hum);

  lcd.setCursor(0, 0);
  lcd.print("Air:");
  lcd.print(airQuality);

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print(" H:");
  lcd.print(hum);

  delay(2000);
}
