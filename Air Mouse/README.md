# Air Mouse 🖱️

## Overview
The Air Mouse project transforms your ESP32 into a wireless, gesture-controlled mouse! By using an MPU6050 accelerometer/gyroscope sensor, you can move your computer's cursor just by waving your hand in the air.

### Project Goals
- Create a wearable or handheld wireless mouse.
- Use motion sensing (IMU) to control PC cursor movement.
- Implement Bluetooth Low Energy (BLE) for a driver-free experience.

---

## Components Used
- **ESP32** (with BLE capability)
- **MPU6050** (Motion sensor)
- **Push Button** (For Left Click)

---

## How it Works
1. The **MPU6050** detects the tilt and acceleration of your hand.
2. The ESP32 processes this motion data into X and Y coordinates.
3. Using the **BleMouse** library, the ESP32 sends these coordinates to your PC/Smartphone as a standard Bluetooth mouse.
4. A dedicated button is used for standard "Left Click" functionality.

### Setup & Usage:
1. Upload the code in the `Air_Mouse` folder.
2. Open Bluetooth settings on your PC/Phone and pair with **"ESP32 Mouse"**.
3. Once connected, tilt the sensor to move the cursor!
