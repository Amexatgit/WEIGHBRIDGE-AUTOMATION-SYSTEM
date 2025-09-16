## 🚗 WEIGH-BRIDGE AUTOMATION SYSTEM

WebBridge Automation is an innovative solution designed to eliminate manual interaction at a weighbridge checkpoint. This system automates the process of recording vehicle entry details, including:

1) Vehicle weight
2) Number plate recognition
3) Timestamp of entry
 
All data is captured and logged in real-time into a MySQL database, creating a seamless and efficient workflow.

--------------------------------------------------------------------------------------------------------------------------------------

## 🔧 TECH STACK

1) Programming Language: C++ *(Java optional for future enhancement)*
2) Database: MySQL
3) Hardware Interface: Microcontroller integration with sensors and peripherals

--------------------------------------------------------------------------------------------------------------------------------------

## 🧠 CORE FUNCTIONALITIES

1. Vehicle Detection

   Captures vehicle entry on a bridge-like platform.

2. Weight Measurement

   Uses a Load Cell to read the vehicle’s weight.
   Microcontroller converts analog signals to digital and sends them to the system.

3. Number Plate Recognition

   Uses a camera module for license plate scanning.
   Can be integrated with OpenCV for future enhancement.

4. Real-time Data Logging

   Stores data in a MySQL database with timestamps.

--------------------------------------------------------------------------------------------------------------------------------------

## ⚙️ HARDWARE COMPONENTS

 ------------------------------------------------------------------------------------------
| Component               | Purpose                                                        |
| ----------------------- | -------------------------------------------------------------- |
| 1. Load Cell            | Measures vehicle weight                                        |
| 2. Microcontroller      | Converts analog weight signals to digital data                 |
| 3. Camera Module        | Captures number plate image                                    |
| 4. Wires                | Electrical connections                                         |
| 5. Battery (5V–20V)     | Powers load cell, microcontroller, and camera                  |
| 6. Sample Weights       | Used for testing (dummy weights: 2kg, 5kg, etc.)               |
| 7. Bridge Setup         | Cardboard model to simulate vehicle platform                   |
| 8. Laptop               | Hosts the database and interface for data processing & storage |
 ------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------

## 🖥️ SYSTEM ARCHITECTURE

![alt text](<LOAD CELL.png>)

--------------------------------------------------------------------------------------------------------------------------------------

