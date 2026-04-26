# Projects Under Innotex Student Workshop

Welcome to the **Innoticx Student Workspace**. This repository contains a collection of advanced IoT, Robotics, and Embedded Systems projects designed for hands-on learning and real-world application.

---

## 📂 Project List

### 1. [Smart Greenhouse](Smart%20Greenhouse/)
A comprehensive environmental monitoring system that tracks soil moisture, temperature, humidity, and gas levels, with full Adafruit IO cloud integration.

### 2. [Smart Home Automation](Smart%20Home%20Automation/)
Intelligent lighting control using PIR motion sensors and LDR light sensors. Features automatic logic and remote manual override via the cloud.

### 3. [AQI Monitoring System](AQI%20Monitoring%20System/)
An air quality station that monitors harmful gases, temperature, and humidity, displaying real-time data on an I2C LCD and syncing with Adafruit IO.

### 4. [Water Level Monitoring System](Water%20Level%20Monitoring%20System/)
A smart tank management system using ultrasonic sensors to measure water depth and automatically control a pump via a relay.

### 5. [Air Mouse](Air%20Mouse/)
A wireless, motion-controlled mouse that uses an MPU6050 sensor and Bluetooth Low Energy (BLE) to control your PC cursor with hand gestures.

### 6. [Hand Gesture Music Remote](Hand%20Gesture%20Music%20Remote/)
Magic-like media control! Use touchless hand gestures (detected by ultrasonic sensors) to Play, Pause, and Skip tracks via BLE Keyboard.

### 7. [The Secret Digital Lock](The%20secret%20Digital%20Lock/)
A high-security lock system that uses a "Secret Knock" (vibration pattern) to unlock, with real-time access logging to Adafruit IO.

### 8. [ESP32 Bluetooth Gamepad](ESP32%20Bluetooth%20Gamepad/)
Transform your ESP32 into a professional wireless game controller for PC and Mobile using BLE, a joystick, and buttons.

---

## 🛠️ General Setup Instructions
1. **Libraries**: Most projects require libraries like `DHT`, `Adafruit MQTT`, `LiquidCrystal_I2C`, `BleMouse`, `BleGamepad`, and `BleKeyboard`.
2. **Credentials**: For IoT projects, always update your `WIFI_SSID`, `WIFI_PASS`, `AIO_USERNAME`, and `AIO_KEY` in the source code.
3. **Connections**: Pin diagrams and connection details are provided in the individual project READMEs.

Happy Coding! 🚀
