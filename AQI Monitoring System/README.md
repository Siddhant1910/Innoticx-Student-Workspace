# AQI Monitoring System 🌬️

## Overview
The AQI Monitoring System is an IoT-based air quality monitoring project that tracks environmental data in real-time. It measures air quality (MQ-135), temperature, and humidity (DHT11), and displays the information on an I2C LCD screen.

### Project Goals
- Monitor harmful gases and smoke levels using the MQ-135 sensor.
- Track ambient temperature and humidity with the DHT11 sensor.
- Provide a local visual display for quick data reading.
- Upload data to the cloud for remote monitoring.

---

## Components Used
- **ESP32** (Brain of the project)
- **MQ-135** Gas Sensor (Air quality)
- **DHT11** Sensor (Temp/Hum)
- **LCD 16x2 (I2C)** (Display)

---

## Adafruit IO Setup ☁️
This project uses **Adafruit IO** for remote data tracking. You can view your room's air quality and climate from anywhere in the world!

### How it works:
1. The ESP32 reads analog values from MQ-135 and digital data from DHT11.
2. It displays these values on the LCD for local monitoring.
3. Every 5 seconds, it pushes the updated values to your Adafruit IO dashboard via WiFi.

### Dashboard Setup:
1. Go to [Adafruit IO](https://io.adafruit.com/) and create an account.
2. Create three **Feeds**:
   - `temperature`
   - `humidity`
   - `airquality`
3. Create a **Dashboard** and add blocks (Gauges, Charts, or Stream) linked to these feeds.

### Code Setup:
Open `AQI_Monitoring_Adafruit.ino` and replace the following lines with your own credentials:
```cpp
#define IO_USERNAME "your_username"
#define IO_KEY      "your_aio_key"
#define WIFI_SSID   "your_wifi"
#define WIFI_PASS   "your_password"
```

### What you will see:
- **Temperature & Humidity**: Real-time graphs showing climate changes.
- **Air Quality**: A gauge showing current gas levels. If the value goes up (e.g., near smoke), you'll see the spike instantly on your dashboard!
