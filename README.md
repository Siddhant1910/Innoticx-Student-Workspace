# Innoticx-Student-Workspace

## 🚀 Recent Updates
We've added several new advanced IoT and Bluetooth projects to the workspace, each complete with component interfacing, combined logic, and Adafruit IO integration.

### New Projects Added:
- **AQI Monitoring System**: Air quality (MQ-135) and climate (DHT11) monitoring with LCD display and cloud logging.
- **Smart Home Automation**: Motion (PIR) and light (LDR) based lighting automation with remote override.
- **Water Level Monitoring System**: Ultrasonic-based tank monitoring with auto-pump control and IoT status updates.
- **Air Mouse**: Gesture-controlled wireless mouse using MPU6050 and BLE.
- **Hand Gesture Music Remote**: Touchless media control using dual ultrasonic sensors and BLE Keyboard.
- **The Secret Digital Lock**: Upgraded with full IoT monitoring for access attempts and lock status.
- **ESP32 Bluetooth Gamepad**: Enhanced with detailed setup guides and visual feedback.

---

🌱 Greenhouse Monitoring System – Project Overview
This project is a simple yet effective Greenhouse Monitoring System built using an ESP32 microcontroller and multiple environmental sensors. The system reads real-time data from:
- DHT11 sensor → measures temperature and humidity
- Soil moisture sensor → measures soil wetness level
- MQ2 gas sensor → detects harmful gases and smoke

The ESP32 collects all sensor values, processes them, converts raw readings into meaningful data (such as soil moisture percentage), and prints the results to the Serial Monitor. This setup allows continuous monitoring of important greenhouse conditions such as temperature, humidity, soil moisture, and air quality.
The project serves as a foundation for building a complete IoT-based greenhouse system, where the data can later be uploaded to cloud platforms like Firebase, MQTT dashboards, or IoT apps for remote monitoring and automation.
