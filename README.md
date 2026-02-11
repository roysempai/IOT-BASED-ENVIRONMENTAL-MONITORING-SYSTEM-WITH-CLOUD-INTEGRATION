# IoT-Based Environmental Monitoring System

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation & Setup](#installation--setup)
- [Usage](#usage)
- [Future Enhancements](#future-enhancements)
- [Author](#author)

## Description
This project is an IoT-based environmental monitoring system that measures **temperature, humidity, and air quality** using an **Arduino board**. The data is displayed on an **LCD screen** and sent to the **Arduino IoT Cloud** for remote monitoring.

## Features
- **Temperature & Humidity Monitoring**: Uses a **DHT11 sensor** to measure temperature and humidity.
- **Air Quality Detection**: Uses an **analog gas sensor** to measure air quality levels.
- **LCD Display**: Shows real-time sensor data on a **16x2 I2C LCD**.
- **IoT Connectivity**: Sends data to the **Arduino IoT Cloud** for remote access.

## Hardware Requirements
- **Arduino-compatible board** (e.g., ESP8266/ESP32)
- **DHT11 Temperature & Humidity Sensor**
- **Gas Sensor (MQ series or equivalent)**
- **16x2 I2C LCD Display**
- **Jumper Wires**
- **Breadboard (optional)**

## Software Requirements
- **Arduino IDE**
- **Arduino IoT Cloud account**
- **DHT Sensor Library**
- **LiquidCrystal_I2C Library**
- **Wire Library**

## Installation & Setup
1. **Install the Required Libraries** in Arduino IDE:
   ```sh
   # Install via Arduino Library Manager
   DHT sensor library
   LiquidCrystal I2C
   Wire
   ```
2. **Connect the Hardware**:
   - **DHT11**: Connect **VCC to 3.3V/5V**, **GND to GND**, and **Data to GPIO2 (D4)**.
   - **Gas Sensor**: Connect **Analog pin to A0**, **VCC to 5V**, and **GND to GND**.
   - **LCD (I2C)**: Connect **SDA to GPIO4 (D2)**, **SCL to GPIO5 (D1)**.

3. **Upload the Code**:
   - Open the Arduino IDE and upload `main.ino` to your board.
   - Ensure you update the **Arduino IoT Cloud credentials** in `arduino_secrets.h`.

4. **Monitor Data**:
   - View data in the **Serial Monitor**.
   - Observe real-time values on the **LCD screen**.
   - Access data remotely via **Arduino IoT Cloud**.

## Usage
- Power on the device.
- The **LCD screen** will display temperature, humidity, and air quality.
- Data is updated **every second** and sent to **Arduino IoT Cloud**.

## Future Enhancements
- Add **alerts and notifications** for threshold values.
- Integrate with **Blynk or MQTT** for advanced IoT capabilities.
- Use a **more advanced air quality sensor** for better accuracy.


---


