# Smart Greenhouse Monitoring System 🌱

## Overview
The Smart Greenhouse Monitoring System is an all-in-one environmental tracking solution for modern agriculture. It monitors soil health, ambient climate, and air safety to ensure plants grow in optimal conditions.

### Project Goals
- Monitor soil moisture levels to automate irrigation.
- Track temperature and humidity for climate control.
- Detect harmful gases or smoke for greenhouse safety.
- Stream all data to the cloud for real-time remote monitoring.

---

## Components Used
- **ESP32** (The core controller)
- **DHT11 Sensor** (Temperature & Humidity)
- **Soil Moisture Sensor** (Capacitive/Resistive)
- **MQ2 Gas Sensor** (Smoke & Harmful gases)

---

## Adafruit IO Setup ☁️
This project is fully integrated with **Adafruit IO** using MQTT for efficient, low-latency data streaming.

### How it works:
1. The ESP32 collects data from the DHT11, Soil sensor, and MQ2 sensor.
2. It processes the soil moisture into a percentage (0-100%).
3. Data is published to four separate feeds on your Adafruit dashboard every 10 seconds.

### Dashboard Setup:
1. Create four **Feeds** in Adafruit IO:
   - `temperature`
   - `humidity`
   - `soil`
   - `gas`
2. Create a **Dashboard** and add:
   - **Gauges** for Temperature and Humidity.
   - A **Slider or Gauge** for Soil Moisture.
   - A **Stream or Indicator** for Gas levels.

### Code Setup:
Open `Adafruitio_IOT.ino` and update your WiFi and Adafruit IO credentials:
```cpp
#define WIFI_SSID     "your_wifi"
#define WIFI_PASS     "your_password"
#define AIO_USERNAME   "your_username"
#define AIO_KEY        "your_aio_key"
```

### What you will see:
- **Climate Monitoring**: Real-time updates on your greenhouse temperature and humidity.
- **Irrigation Status**: A visual representation of how dry or wet your soil is.
- **Safety Alerts**: Immediate detection of gas or smoke spikes on your cloud dashboard.
