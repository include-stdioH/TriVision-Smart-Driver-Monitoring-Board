# TriVision-Smart-Driver-Monitoring-Board
ESP32-S3 based Smart Driver Monitoring Sensor Board designed in KiCad.
# TriVision – Smart Driver Monitoring Sensor Board

## Overview

TriVision is a custom-designed ESP32-S3-based sensor board developed for intelligent driver monitoring and vehicle safety applications. The board integrates biometric and motion sensing capabilities to detect driver fatigue, drowsiness, distraction, and abnormal driving conditions.

This project was designed using KiCad and includes complete schematic design, PCB layout, component placement, routing, and 3D visualization.

---

## Features

* ESP32-S3 based processing unit
* Heart-rate and SpO₂ monitoring using MAX30102
* Motion and orientation sensing using MPU6050
* Driver alert buzzer system
* Status indication LEDs
* USB Type-C power input
* On-board 3.3V regulation using AMS1117
* Compact custom PCB design
* Ready for IoT and AI-based driver monitoring applications

---

## Hardware Components

| Component        | Function                    |
| ---------------- | --------------------------- |
| ESP32-S3-WROOM-1 | Main microcontroller        |
| MAX30102         | Heart-rate and SpO₂ sensor  |
| MPU6050          | Accelerometer and gyroscope |
| AMS1117-3.3      | Voltage regulator           |
| USB Type-C       | Power input                 |
| Buzzer           | Driver warning alerts       |
| LEDs             | System status indication    |

---

## System Architecture

USB-C Power Input → AMS1117 → 3.3V Rail

ESP32-S3 ↔ MAX30102 (I²C)

ESP32-S3 ↔ MPU6050 (I²C)

ESP32-S3 → Buzzer

ESP32-S3 → Status LEDs

---

## PCB Design Highlights

* Two-layer PCB
* ESP32 antenna keep-out region implemented
* Dedicated 3.3V power distribution
* Decoupling capacitors placed near critical devices
* I²C pull-up resistors included
* Designed following standard PCB layout practices

---

## Design Tools

* KiCad 10
* GitHub

---

## Future Improvements

* Camera-based drowsiness detection
* CAN Bus integration
* Vehicle telemetry support
* Edge AI processing
* Mobile application integration

---

## Author

Anushri Logesh

Electronics and Communication Engineering

Embedded Systems & AI Enthusiast
