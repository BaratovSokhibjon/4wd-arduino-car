# Autonomous 4WD Robot with Ultrasonic Sensor, Buzzer, and Servo

An autonomous Arduino-powered 4WD robot designed to navigate around obstacles using an ultrasonic sensor for distance measurement, a buzzer for feedback, and a servo motor for directional control. This project is part of the **V2X Course**.

---

## Project Overview

This robot uses:
- An **ultrasonic sensor** (HC-SR04) to detect obstacles in its path.
- A **buzzer** for audio feedback when an obstacle is detected.
- A **servo motor** to help the ultrasonic sensor scan for alternative paths.
- Motor control via an **H-Bridge (L298N)** to drive the 4WD setup.

The robot stops, signals with a buzzer when obstacles are nearby, and scans to determine the best route, providing autonomous navigation capabilities.

---

## Hardware Requirements

- **Arduino Uno** or compatible microcontroller
- **Ultrasonic Sensor (HC-SR04)**
- **Buzzer**
- **Servo Motor**
- **L298N Motor Driver** (or similar H-Bridge for motor control)
- **4WD Chassis with Motors**

---

## Hardware Setup

### 1. **Ultrasonic Sensor (HC-SR04)**
   - **VCC**: Arduino **5V**
   - **Trig**: Arduino **D2**
   - **Echo**: Arduino **D3**
   - **GND**: Arduino **GND**

### 2. **Buzzer**
   - **Positive (+)**: Arduino **D4**
   - **Negative (-)**: Arduino **GND**

### 3. **Servo Motor**
   - **Signal**: Arduino **D9**
   - **VCC**: Arduino **5V**
   - **GND**: Arduino **GND**

### 4. **Motor Control (H-Bridge, e.g., L298N)**
   - **Left Motor Control Pins**:
     - **IN1**: Arduino **D5**
     - **IN2**: Arduino **D6**
   - **Right Motor Control Pins**:
     - **IN3**: Arduino **D7**
     - **IN4**: Arduino **D8**

---

## Code Explanation

This project features modular code with each component performing specific functions:

- **Ultrasonic Sensor**: Measures the distance to obstacles in front of the robot.
- **Buzzer**: Signals when an obstacle is detected within a preset range.
- **Servo Motor**: Rotates the ultrasonic sensor to scan the left and right for available space when an obstacle is detected.
- **Motor Control**: Uses the L298N H-Bridge to control forward, left, and right movement of the robot.

The code directs the robot to:
1. **Move forward** until an obstacle is detected.
2. **Stop** and activate the **buzzer** when an obstacle is within the "safe distance."
3. **Scan left and right** with the servo motor.
4. **Turn in the direction** with more space to avoid the obstacle.

---

## Team Members

| Name                  | ID        |
| --------------------- | --------- |
| Baratov Sokhibjon     | 12225259  |
| Imetov Daniiar        | 12235609  |
| Nematjonov Bahodir    | 12225254  |

---

### Getting Started

1. Connect each component as per the hardware setup above.
2. Upload the code to the Arduino.
3. Power on the robot, and it will autonomously navigate around obstacles.

Enjoy building and coding your autonomous 4WD robot!
