# The Secret Digital Lock 🔒

## Overview
This is a "Secret Knock" digital lock system. Instead of a key or a password, you use a specific vibration pattern (knocks) to unlock it. It’s a fun, interactive way to secure a drawer or a box.

### Project Goals
- Implement a pattern-recognition security system.
- Use vibration sensing for input.
- Provide visual status updates on an LCD.
- Log access attempts to the cloud.

---

## Components Used
- **ESP32** (Controller)
- **Vibration Sensor** (Detects knocks)
- **LCD 16x2 (I2C)** (Shows status: "Locked" or "Unlocked")
- **Red & Green LEDs** (Visual indicators)

---

## Adafruit IO Setup ☁️
Monitor your secret lock remotely! This project uses **MQTT** to communicate with Adafruit IO.

### How it works:
1. The system waits for exactly **3 knocks** with a specific timing.
2. If the pattern is correct, it unlocks and updates the status.
3. **IoT Tracking**: Every time a knock is detected, it is sent to the cloud. The final "Locked" or "Unlocked" status is also pushed to the dashboard.

### Dashboard Setup:
1. Create two **Feeds**:
   - `knock-count`
   - `lock-status`
2. Add a **Text Display** for `lock-status` and a **Gauge** for `knock-count`.

### Code Setup:
Update your WiFi and Adafruit IO credentials in `Secret_digital_lock_interfacing_adafruit.ino`:
```cpp
#define WIFI_SSID     "your_wifi"
#define WIFI_PASS     "your_password"
#define AIO_USERNAME   "your_username"
#define AIO_KEY        "your_aio_key"
```

### What you will see:
- **Security Log**: Your dashboard will show "LOCKED" or "UNLOCKED" in real-time.
- **Knock Counter**: See the count increase as you perform the secret knock!
