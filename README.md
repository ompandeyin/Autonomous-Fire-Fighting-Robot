# 🔥 Autonomous Fire-Fighting Robot

Arduino-based autonomous robotic system designed to detect and extinguish small-scale indoor fires using multi-sensor integration and real-time embedded control logic.

📌 Problem Statement

Fire emergencies require rapid response while minimizing human risk.
This project develops a low-cost autonomous robotic system capable of detecting and suppressing fire in indoor environments.

## ⚙️ System Architecture

The robot integrates:

- Arduino Uno (Control Unit)
- Flame Sensors (Fire Detection)
- MQ2 Gas Sensor (Smoke Detection)
- L293D Motor Driver (Movement Control)
- Ultrasonic Sensor (Obstacle Avoidance)
- Relay Module (Pump Activation)
- SG90 Servo Motor (Directional Spray)
- Water Pump Mechanism

## 🚀 Performance Metrics

- Fire detection within **25–30 cm**
- Response time: **2–3 seconds**
- Fire extinguished within **1–2 attempts**

Autonomous obstacle-aware navigation

🧠 Working Logic

1. Sensors continuously monitor environment.
2. Flame detection triggers directional movement.
3. Ultrasonic sensor ensures obstacle-free navigation.
4. Relay activates water pump.
5. Servo directs spray toward flame.
6. System resets after suppression.

🛠 Tech Stack

Arduino (Embedded C/C++)

Sensor Fusion

Motor Driver (L293D)

MQ2 Gas Sensor

Servo Motor Control

### Block Diagram
![Block Diagram](diagrams/block_diagram.png)

### Circuit Diagram
![Circuit Diagram](diagrams/circuit_diagram.png)

🎥 Demo

[Watch Demo Video](https://drive.google.com/file/d/194iEqIM6P0hewS7NzqkATR1v3pVAi7m6/view?usp=sharing
)


📌 Future Enhancements

AI-based fire classification

Thermal camera integration

IoT-based monitoring system

Intelligent path planning algorithms


## 👨‍🎓 Author
**Om Pandey**  
Computer Science Student  
Lovely Professional University, Punjab
