# Smart Home Automation 🏠

## Overview
The Smart Home Automation project is designed to intelligently control home lighting. It uses motion and light sensors to ensure lights are only ON when someone is in the room and the ambient light is low, saving energy automatically.

### Project Goals
- Automate lighting based on occupancy and brightness.
- Provide remote manual control via the cloud.
- Save energy by preventing lights from staying ON unnecessarily.

---

## Components Used
- **ESP32** (Main Controller)
- **PIR Motion Sensor** (Detects presence)
- **LDR (Photoresistor)** (Detects room brightness)
- **Relay Module** (Controls the high-voltage bulb/appliance)

---

## Adafruit IO Setup ☁️
Take control of your home from anywhere! This project integrates with **Adafruit IO** for smart monitoring and manual override.

### How it works:
1. **Auto Mode**: The ESP32 turns on the light only if **Motion is detected** AND **Light is low**.
2. **IoT Sync**: The motion and light levels are sent to your dashboard in real-time.
3. **Manual Override**: You can turn the light ON/OFF manually from your Adafruit dashboard button, which overrides the auto-logic.

### Dashboard Setup:
1. Create three **Feeds** in Adafruit IO:
   - `motion`
   - `light`
   - `relay`
2. Create a **Dashboard** and add:
   - A **Toggle Switch** for the `relay` feed.
   - **Indicators/Charts** for `motion` and `light`.

### Code Setup:
Update your credentials in `Smart_home_automation_combined_adafruit.ino`:
```cpp
#define IO_USERNAME "your_username"
#define IO_KEY      "your_aio_key"
#define WIFI_SSID   "your_wifi"
#define WIFI_PASS   "your_password"
```

### What you will see:
- **Motion Alert**: A virtual LED on your dashboard lights up when motion is detected.
- **Light Level**: A graph showing how bright your room is.
- **Remote Switch**: Click the button on your phone, and the real bulb in your room will turn ON or OFF!
