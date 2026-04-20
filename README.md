Project Title:
Smart Radar and Password Protected Alarm System
​Objective:
The aim of this project is to design and implement a physical circuit of an audible and visual smart alarm system using the Arduino. The system scans a 360-degree area using a servo motor and an ultrasonic sensor. If any object is detected within the scanned area, its distance is displayed on the LCD screen, a green LED illuminates, and the system continues scanning. If the object approaches closer than the predetermined distance, the alarm system is activated; the green LED turns off, the red LED turns on, the buzzer starts beeping, the scanning stops, and the system locks itself. The alarm system remains active even when the object is moved away until the correct password is entered via the 3x4 matrix keypad.

​

​Module Distribution:
​1-Ultrasonic Distance Detection Module
2-​LCD Display Module (I2C/Parallel)
​3-Servo Motor Scanning Module
​4-Alarm Module (LED and buzzer)
​5-Keypad Security Module
6-Real-Time Radar Visualization Module (Serial Port Mapping)

​Hardware:
The project will be built using the Arduino Uno platform. The system will be programmed using the Arduino (C++) language. The design focuses on integrating real-time sensor data with mechanical movement and visual feedback.
​Workload Justification:
This project involves complex hardware-software integration including PWM-based servo control, ultrasonic pulse timing, matrix keypad scanning, and real-time serial data transmission. To meet the visualization requirement, the system sends angle and distance data to the Serial Monitor, allowing for a graphical radar representation on a PC.

​Task Sharing:
Begüm Asya Eroğlu: Development of Arduino code structure, ultrasonic sensing algorithms, LCD display integration, and Serial Monitor data formatting.
Fırat Cem Başoğlu: Development of servo motor control, alarm system hardware (LED + buzzer), keypad password authentication, and PC-Arduino serial communication.
