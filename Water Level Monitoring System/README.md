# Water Level Monitoring System 💧

## Overview
The Water Level Monitoring System is an automated solution for managing water tanks. It measures the water level using sound waves and automatically turns a pump ON or OFF to prevent overflow or dry-running.

### Project Goals
- Monitor tank water level in real-time.
- Automate pump control based on depth.
- Provide visual (LED) and audible (Buzzer) alerts.
- Enable remote monitoring and control via IoT.

---

## Components Used
- **ESP32** (Main Controller)
- **Ultrasonic Sensor (HC-SR04)** (Measures distance)
- **Relay Module** (Controls the water pump)
- **LED & Buzzer** (Indicators for Low/Full levels)

---

## Adafruit IO Setup ☁️
Monitor your tank and control your pump from your smartphone!

### How it works:
1. **Auto Mode**: The pump turns ON when the water is **LOW** (Distance > 20cm) and turns OFF when **FULL** (Distance < 10cm).
2. **Cloud Sync**: The exact distance (water level) and pump status are sent to your Adafruit dashboard.
3. **Manual Override**: If you need to fill the tank manually, you can flip the "Pump" switch on your dashboard to take control.

### Dashboard Setup:
1. Create three **Feeds**:
   - `distance` (Water level)
   - `status` (Text status: LOW, MEDIUM, FULL)
   - `pump` (Manual control)
2. Create a **Dashboard** and add:
   - A **Gauge** for `distance`.
   - A **Text Block** for `status`.
   - A **Toggle Switch** for the `pump` feed.

### Code Setup:
Update your credentials in `Water_Level_Monitoring_Adafruit.ino`:
```cpp
#define IO_USERNAME "your_username"
#define IO_KEY      "your_aio_key"
#define WIFI_SSID   "your_wifi"
#define WIFI_PASS   "your_password"
```

### What you will see:
- **Water Level Gauge**: See exactly how much water is left.
- **Status Indicator**: Instantly see if the tank is "FULL", "MEDIUM", or "LOW".
- **Remote Control**: Use the switch on your phone to turn the pump ON or OFF from anywhere!
