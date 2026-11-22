# Automatic Obstacle-Detection & Braking Car (Tesla-Inspired Prototype)

An autonomous collision-avoidance vehicle prototype inspired by Tesla's Automatic Emergency Braking (AEB) system. Built and showcased at the **Vigyan Mela (Science Exhibition)**, where it secured **1st Place at the District Level (Burhanpur)** and represented the district at the **State Level (Indore)**.

## How It Works
- **Real-Time Distance Sensing:** Uses an Ultrasonic Sensor (HC-SR04) mounted at the front to continuously measure the distance of objects ahead.
- **Instant Braking:** If any person or obstacle suddenly appears within the critical threshold (25 cm), the microcontroller immediately cuts power to the drive motors to halt the vehicle.
- **Alert System:** Triggers a brake indicator/buzzer upon obstacle detection.

## Hardware Components Used
- Arduino Uno (Microcontroller)
- HC-SR04 Ultrasonic Sensor
- L298N Dual H-Bridge Motor Driver
- 4x BO DC Motors & Chassis
- Li-ion Battery Pack & Alert LED/Buzzer
