# Hand Gesture Music Remote 🎵

## Overview
Control your music like magic! This project uses ultrasonic sensors to detect hand gestures, allowing you to Play, Pause, or Skip tracks without touching your phone or computer.

### Project Goals
- Implement touchless media control.
- Use distance sensing to trigger keyboard shortcuts.
- Use BLE Keyboard library for wireless interaction.

---

## Components Used
- **ESP32** (with BLE capability)
- **2x Ultrasonic Sensors (HC-SR04)**
- **2x LEDs** (Feedback for gestures)

---

## How it Works
1. Two ultrasonic sensors act as "virtual buttons" in the air.
2. **Sensor 1**: If you bring your hand close, it triggers a **Play/Pause** command.
3. **Sensor 2**: If you bring your hand close, it triggers a **Next Track (Skip)** command.
4. The ESP32 acts as a Bluetooth Keyboard and "types" the media keys for you.

### Setup & Usage:
1. Upload the code in `Hand_Gesture_media_Control_interfacing`.
2. Pair your device with **"Magic-Music"** via Bluetooth.
3. Wave your hand in front of the sensors to control your favorite music player (Spotify, YouTube, etc.).
