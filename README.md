## 🚗 WEIGH-BRIDGE AUTOMATION SYSTEM

WebBridge Automation is an innovative solution designed to eliminate manual interaction at a weighbridge checkpoint.  
This system automates the process of recording vehicle entry details, including:

1. Vehicle weight  
2. Number plate recognition  
3. Timestamp of entry  

All data is captured and logged in real time into a database, creating a seamless and efficient workflow.

---

## 🔧 TECH STACK

1. **Programming Language:** C++ *(Java optional for future enhancement)*  
2. **Database:** MySQL *(with additional support for MS Excel and CSV storage)*  
3. **Hardware Interface:** Microcontroller integration with sensors and peripherals  

---

## 🧠 CORE FUNCTIONALITIES

### 1. Vehicle Detection
Captures vehicle entry on a bridge-like platform using IR sensors or ultrasonic sensors.

### 2. Weight Measurement
Uses a Load Cell to read the vehicle’s weight.  
Microcontroller converts analog signals to digital and sends them to the system.

### 3. Number Plate Recognition
Uses a camera module for license plate scanning.  
Can be integrated with **OpenCV** for future enhancement.

### 4. Real-Time Data Logging
Stores data in a **MySQL** database with timestamps.

---

## 📦 NEW DATA STORAGE SUPPORT

The system now supports **multiple data storage formats**, enabling greater flexibility and compatibility:

| Format | Description | Use Case |
|---------|--------------|----------|
| **MySQL** | Primary database for real-time storage | Core backend data handling |
| **CSV** | Lightweight, portable text-based format | For exporting logs and reports |
| **Microsoft Excel (.xlsx)** | Structured spreadsheet format | For detailed analysis and archiving |

### 💾 Export/Import
Users can export data in **CSV** or **Excel** format, or import it back into the system for further processing.  
This allows easy integration with external analytics tools or backups.

---

## 💻 PLATFORM SUPPORT

The project can now run on multiple platforms beyond standard PCs:

| Platform | Status | Notes |
|-----------|---------|-------|
| **Arduino / ESP32** | ✅ Supported | Core microcontroller integration |
| **Raspberry Pi** | 🧩 New | Suitable for lightweight on-device data logging and automation |
| **Other SBCs (BeagleBone, Odroid)** | 🔄 Planned | Compatible setup in progress |

2. Install dependencies:
   ```bash
   sudo apt update && sudo apt install python3 mysql-server -y


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

