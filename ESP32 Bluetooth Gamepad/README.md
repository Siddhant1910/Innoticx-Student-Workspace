# ESP32 Bluetooth Gamepad 🎮

## Overview
Turn your ESP32 into a fully functional wireless game controller! This project uses a joystick and buttons to simulate a Bluetooth gamepad that works with PCs, Android phones, and consoles.

### Project Goals
- Build a custom DIY wireless controller.
- Map physical joystick and buttons to standard HID gamepad inputs.
- Use BLE (Bluetooth Low Energy) for low-latency gaming.

---

## Components Used
- **ESP32** (Brain of the project)
- **Analog Joystick** (X and Y axis)
- **4 Push Buttons** (Action buttons)
- **4 LEDs** (Visual feedback for button presses)

---

## How it Works
1. The ESP32 reads the analog values from the joystick and digital states from the buttons.
2. It maps the 0-4095 analog range of the joystick to the standard gamepad range.
3. When a button is pressed, the corresponding LED lights up, and a "Button Press" signal is sent via Bluetooth.
4. Your PC/Phone recognizes the ESP32 as a standard Gamepad.

### Setup & Usage:
1. Upload the code from `Bluetooth_Gamepad_interafing`.
2. Pair your device with **"GamePad"** via Bluetooth.
3. Open a game or a controller tester website to see your DIY controller in action!
