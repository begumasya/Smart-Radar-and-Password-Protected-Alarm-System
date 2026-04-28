📡 Smart Radar and Password Protected Alarm System
🎯 Project Objective

This project aims to design and implement a smart alarm system using an Arduino Uno. The system performs a 360-degree scan using a servo motor and an ultrasonic sensor to detect objects in its surroundings.

When an object is detected, the system displays the distance on an LCD screen and activates a green LED. If the object comes closer than a predefined threshold distance, the system triggers an alarm:

The green LED turns off
The red LED turns on
The buzzer starts beeping
The scanning process stops
The system locks itself

The alarm remains active even if the object moves away, and it can only be deactivated by entering the correct password via a 3x4 matrix keypad.

🧩 System Modules
Ultrasonic Distance Detection Module
LCD Display Module (I2C / Parallel)
Servo Motor Scanning Module
Alarm Module (LED & Buzzer)
Keypad Security Module
Real-Time Radar Visualization Module (Serial Port Mapping)
🔧 Hardware & Technologies
Arduino Uno
Ultrasonic Sensor (HC-SR04)
Servo Motor
16x2 LCD Display
3x4 Matrix Keypad
LEDs (Red & Green)
Buzzer

Programming Language: Arduino (C/C++)

⚙️ System Design

The system integrates real-time sensor data with mechanical movement and visual feedback. The ultrasonic sensor continuously measures distance while the servo motor scans the environment.

Distance and angle data are transmitted via the serial port to enable real-time radar visualization on a computer.

💻 Real-Time Visualization

The system sends angle and distance data to the Serial Monitor, allowing a radar-like graphical representation to be created on a PC.

🧠 Workload Justification

This project involves complex hardware and software integration, including:

PWM-based servo motor control
Ultrasonic pulse timing and distance calculation
Matrix keypad scanning and password validation
LCD communication
Real-time serial data transmission
👥 Task Distribution
Begüm Asya Eroğlu
Arduino code structure
Ultrasonic sensing algorithms
LCD integration
Serial data formatting
Fırat Cem Başoğlu
Servo motor control
Alarm system (LED + buzzer)
Keypad authentication
Serial communication (PC-Arduino)
🚀 How to Run
Connect all hardware components according to the circuit diagram.
Upload the Arduino code to the Arduino Uno.
Open the Serial Monitor to observe radar data.
Power the system and observe scanning behavior.
📌 Notes
The threshold distance can be adjusted in the code.
The password is defined in the Arduino program.
Make sure all connections are secure before powering the system.
