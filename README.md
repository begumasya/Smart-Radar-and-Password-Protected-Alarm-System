Smart-Radar-and-Password-Protected-Alarm-System


Project Objective:

This project aims to design and implement a radar-based security system using an Arduino Uno. The system scans its environment using a servo motor and an ultrasonic sensor. The measured angle and distance values are transmitted to a computer via serial communication and visualized through a radar interface developed in the Processing application.

During operation, the servo motor sweeps between 0° and 180° while the ultrasonic sensor continuously measures distance. If an object is detected closer than a predefined threshold, the system displays a warning message on the LCD screen and activates the red LED. When no close object is detected, the system indicates a safe state using the green LED.

The system can be controlled using an IR remote. By entering the correct password, the user can turn the system on or off. When the system is turned off, the servo motor stops, LEDs are deactivated, and scanning halts until the correct password is entered again.


System Modules:

-Ultrasonic Distance Detection Module
-Servo Motor Scanning Module
-LCD Display Module
-LED Warning Module
-IR Remote Password Control Module
-Serial Communication Module
-Real-Time Radar Visualization Module (Processing)


Hardware and Technologies:

-Arduino Uno
-Ultrasonic Sensor (HC-SR04)
-Servo Motor
-16x2 LCD Display
-IR Receiver and Remote Controller
-Red and Green LEDs
-Buzzer
-Processing Application for visualization


Programming Languages:

-Arduino (C/C++)
-Processing


System Design:

The ultrasonic sensor measures distance by transmitting and receiving sound waves. The servo motor rotates the sensor across a defined angle range, allowing the system to scan the environment.

Distance and angle data are sent to the computer via serial communication. These values are used in the Processing application to generate a real-time radar visualization.

The LCD provides feedback to the user by displaying distance values or warning messages. The LED system reflects the current state: green indicates normal conditions, while red indicates a nearby object.


Real-Time Visualization:

A radar interface has been developed using the Processing environment. The Arduino sends data in the format: angle, distance. This data is read and visualized in real time, creating a radar-like display on the computer.


Password Control:

The system uses an IR remote controller instead of a keypad for password input.

Entering “2015” turns the system off
Entering “2009” turns the system on

A confirmation button on the remote is used to submit the password. If the password is incorrect, the system provides feedback via the LCD.


Task Distribution:

Begüm Asya Eroğlu

-Ultrasonic sensing logic
-LCD integration
-Serial data formatting
-Arduino–computer communication
-Proteus simulation and circuit validation
-Contribution to Arduino code implementation

Fırat Cem Başoğlu

-Servo motor control
-LED and warning system
-IR remote integration
-Password handling logic
-Processing radar interface
-Contribution to Arduino code implementation
