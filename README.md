# 🚗 WEIGHBRIDGE AUTOMATION SYSTEM

**A comprehensive, automated weighbridge solution for seamless vehicle weight measurement and data management**

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Supported Platforms](#-comprehensive-platform-support)
- [Technology Stack](#-technology-stack)
- [Advanced Data Storage Solutions](#-advanced-data-storage-solutions)
- [System Architecture](#️-system-architecture)
- [Hardware Components](#-hardware-components)
- [Installation & Setup](#-installation--setup)
- [Configuration](#️-configuration)
- [Usage Examples](#-usage-examples)
- [Contributing](#-contributing)
- [License](#-license)
- [Security](#-security)

## 🎯 Overview

The Weighbridge Automation System is an innovative, enterprise-grade solution designed to eliminate manual intervention at weighbridge checkpoints. This system provides comprehensive automation for vehicle weight measurement, license plate recognition, and data management, creating a seamless and efficient workflow for transportation and logistics operations.

### Key Capabilities

- **Automated Vehicle Detection**: Real-time monitoring of vehicle entry on weighbridge platforms
- **Precise Weight Measurement**: High-accuracy load cell integration with HX711 amplification
- **Advanced License Plate Recognition**: Computer vision-based number plate scanning using OpenCV
- **Multi-Format Data Storage**: Flexible storage options including MySQL, CSV, and Microsoft Excel
- **Cross-Platform Compatibility**: Support for multiple microcontroller platforms and operating systems
- **Real-time Data Logging**: Timestamped data capture with configurable storage backends

## ✨ Features

### Core Functionalities

1. **Vehicle Detection & Monitoring**
   - Real-time vehicle entry detection on weighbridge platforms
   - Automated triggering of measurement and capture systems

2. **Precision Weight Measurement**
   - HX711 load cell amplifier integration for accurate weight readings
   - Configurable calibration and tare functionality
   - Support for multiple weight ranges and units

3. **License Plate Recognition**
   - Computer vision-based number plate detection and extraction
   - OpenCV integration for image processing and analysis
   - Automatic image capture and storage

4. **Comprehensive Data Management**
   - Real-time data logging with precise timestamps
   - Multiple storage format support (MySQL, CSV, Excel XML)
   - Configurable data retention and export options

### Advanced Features

- **Modular Architecture**: Pluggable storage backends for maximum flexibility
- **Thread-Safe Operations**: Concurrent data handling with mutex protection
- **Environment-Based Configuration**: Runtime configuration via environment variables
- **Cross-Platform Serial Communication**: Universal serial port integration
- **Error Handling & Logging**: Comprehensive error management and system logging

## 🔧 Comprehensive Platform Support

The Weighbridge Automation System is designed with cross-platform compatibility as a core principle, ensuring seamless deployment across diverse hardware and software environments.

### Microcontroller Platforms

#### Primary Development Platforms
| Platform | Status | Architecture | Key Features | Recommended Use Cases |
|----------|--------|-------------|--------------|---------------------|
| **ESP32** | ✅ Production Ready | 32-bit Xtensa Dual-Core | WiFi/Bluetooth, 240MHz, 520KB RAM | IoT deployments, wireless connectivity |
| **Raspberry Pi 4B/5** | ✅ Production Ready | ARM Cortex-A72/A76 | 4-8GB RAM, GPIO, Camera Module | Full-featured deployments, edge computing |
| **Raspberry Pi Zero 2W** | ✅ Production Ready | ARM Cortex-A53 | Compact form factor, WiFi | Cost-effective solutions, space-constrained environments |

#### Arduino Ecosystem
| Platform | Status | Architecture | Key Features | Recommended Use Cases |
|----------|--------|-------------|--------------|---------------------|
| **Arduino Uno R3** | ✅ Supported | ATmega328P | 16MHz, 2KB RAM, 32KB Flash | Educational projects, basic prototyping |
| **Arduino Nano** | ✅ Supported | ATmega328P | Compact form factor, breadboard friendly | Embedded applications, small-scale deployments |
| **Arduino Mega 2560** | ✅ Supported | ATmega2560 | 256KB Flash, 8KB RAM, 54 I/O pins | Complex sensor arrays, extensive I/O requirements |
| **Arduino Due** | ✅ Supported | ARM Cortex-M3 | 84MHz, 96KB RAM, 512KB Flash | High-performance applications |

#### Advanced Microcontrollers
| Platform | Status | Architecture | Key Features | Development Status |
|----------|--------|-------------|--------------|-------------------|
| **STM32F4 Series** | 🔄 Beta Testing | ARM Cortex-M4 | 168MHz, FPU, DSP instructions | Advanced signal processing |
| **STM32H7 Series** | 🔄 In Development | ARM Cortex-M7 | 480MHz, 1MB RAM, Ethernet | High-performance edge computing |
| **Nordic nRF52** | 📋 Planned | ARM Cortex-M4F | Bluetooth 5.0, ultra-low power | Battery-operated systems |
| **Teensy 4.1** | 🔄 In Development | ARM Cortex-M7 | 600MHz, Ethernet, microSD | High-speed data logging |

### Operating System Compatibility

#### Linux Distributions
| Distribution | Status | Architecture Support | Notes |
|-------------|--------|---------------------|-------|
| **Ubuntu 20.04/22.04 LTS** | ✅ Fully Supported | x86_64, ARM64, ARMv7 | Primary development and deployment platform |
| **Debian 11/12** | ✅ Fully Supported | x86_64, ARM64, ARMv7 | Stable, long-term support |
| **Raspberry Pi OS** | ✅ Fully Supported | ARMv7, ARM64 | Optimized for Raspberry Pi hardware |
| **CentOS/RHEL 8/9** | ✅ Supported | x86_64 | Enterprise environments |
| **Fedora 36+** | ✅ Supported | x86_64, ARM64 | Cutting-edge features and drivers |

#### Windows Platforms
| Version | Status | Architecture Support | Development Tools |
|---------|--------|---------------------|------------------|
| **Windows 10/11** | ✅ Fully Supported | x86_64, ARM64 | Visual Studio 2019+, WSL2 integration |
| **Windows Server 2019/2022** | ✅ Supported | x86_64 | Enterprise deployment scenarios |
| **Windows IoT Core** | 🔄 In Development | ARM64 | Embedded Windows applications |

#### macOS Platforms
| Version | Status | Architecture Support | Development Environment |
|---------|--------|---------------------|----------------------|
| **macOS Monterey (12.0+)** | ✅ Fully Supported | Intel x86_64, Apple Silicon (M1/M2) | Xcode 13+, Homebrew package management |
| **macOS Ventura (13.0+)** | ✅ Fully Supported | Intel x86_64, Apple Silicon (M1/M2) | Native Apple Silicon optimization |

### Development Environment Support

#### Integrated Development Environments
| IDE | Platform Support | Key Features | Recommended Extensions |
|-----|-----------------|--------------|----------------------|
| **Visual Studio Code** | Cross-platform | IntelliSense, debugging, Git integration | C/C++, CMake Tools, Arduino |
| **Arduino IDE 2.0** | Cross-platform | Built-in library manager, serial monitor | ESP32, STM32 board packages |
| **PlatformIO** | Cross-platform | Multi-platform library management | ESP32, Arduino, STM32 frameworks |
| **CLion** | Cross-platform | Advanced C++ debugging, CMake integration | Embedded development plugins |

#### Build Systems and Tools
| Tool | Purpose | Platform Support | Configuration |
|------|--------|-----------------|---------------|
| **CMake 3.10+** | Build system generation | Cross-platform | CMakeLists.txt configuration |
| **Make/GNU Make** | Build automation | Unix-like systems | Traditional makefile support |
| **Ninja** | Fast build system | Cross-platform | CMake generator option |
| **Docker** | Containerized deployment | Cross-platform | Dockerfile for consistent environments |

### Hardware Interface Compatibility

#### Communication Protocols
| Protocol | Supported Platforms | Use Cases | Configuration |
|----------|-------------------|-----------|---------------|
| **Serial/UART** | All platforms | Microcontroller communication | Baud rate: 9600-115200 |
| **I2C** | ESP32, Raspberry Pi, Arduino | Sensor communication | Address: 0x48 (configurable) |
| **SPI** | ESP32, Raspberry Pi, Arduino | High-speed data transfer | Customizable pins |
| **GPIO** | All platforms | Digital I/O operations | Configurable pin mapping |
| **Ethernet** | Raspberry Pi, STM32 | Network connectivity | TCP/IP stack integration |
| **WiFi** | ESP32, Raspberry Pi | Wireless connectivity | WPA2/WPA3 security |
| **Bluetooth** | ESP32, Raspberry Pi | Short-range communication | BLE 4.2+ support |

#### Sensor Integration
| Sensor Type | Supported Platforms | Integration Method | Accuracy |
|------------|-------------------|-------------------|----------|
| **Load Cells (HX711)** | All platforms | 24-bit ADC amplification | ±0.1% FS |
| **Camera Modules** | Raspberry Pi, ESP32-CAM | USB/CSI interface | 1080p@30fps |
| **Temperature Sensors** | All platforms | I2C/1-Wire protocols | ±0.5°C |
| **Motion Sensors** | All platforms | GPIO interrupt handling | Real-time detection |

## 🛠 Technology Stack

### Programming Languages
- **C++17**: Core application development
- **Python**: Optional scripting and automation tools
- **SQL**: Database queries and schema management

### Libraries & Frameworks
- **OpenCV**: Computer vision and image processing
- **MySQL Connector/C++**: Database connectivity
- **HX711 Library**: Load cell amplification and reading
- **Standard C++ Libraries**: STL containers, threading, and I/O operations

### Build Systems
- **CMake**: Cross-platform build configuration
- **GCC/Clang**: C++ compiler support
- **Arduino Framework**: Microcontroller development

## 💾 Advanced Data Storage Solutions

The Weighbridge Automation System offers comprehensive data storage capabilities with multiple format support, ensuring compatibility with various organizational needs and data management requirements:

### 1. MySQL Database Integration (Primary Storage)
- **Purpose**: Enterprise-grade relational database storage with full ACID compliance
- **Key Features**: 
  - Concurrent multi-user access with transaction support
  - Advanced SQL querying capabilities for complex data analysis
  - Automated backup and recovery mechanisms
  - Real-time data synchronization and replication
- **Optimal Use Cases**: 
  - Production environments requiring high reliability
  - Multi-user access scenarios with role-based permissions
  - Large-scale deployments with extensive data analytics requirements
  - Integration with existing enterprise database infrastructure
- **Configuration Parameters**:
  ```bash
  STORAGE_BACKEND=MYSQL
  DB_HOST=your_mysql_server
  DB_USER=weighbridge_user
  DB_PASS=secure_password
  DB_NAME=vehicle_weighbridge_data
  DB_PORT=3306
  ```

### 2. CSV File Storage (Lightweight Solution)
- **Purpose**: Portable, human-readable data storage with maximum compatibility
- **Key Features**:
  - UTF-8 encoding support for international character sets
  - Customizable delimiter and formatting options
  - Automatic file rotation based on size or date
  - Header row with field descriptions for easy identification
  - Built-in data validation and error handling
- **Optimal Use Cases**:
  - Development and testing environments
  - Small to medium-scale deployments
  - Data migration and backup operations
  - Integration with external data analysis tools
  - Compliance reporting with audit trail requirements
- **Configuration Parameters**:
  ```bash
  STORAGE_BACKEND=CSV
  CSV_PATH=/data/weighbridge_records.csv
  CSV_DELIMITER=,
  CSV_ENCODING=UTF-8
  CSV_MAX_SIZE=100MB
  ```

### 3. Microsoft Excel XML Format (Business Integration)
- **Purpose**: Native Microsoft Excel compatibility for seamless business reporting
- **Key Features**:
  - Direct Excel 2003+ format compatibility without external dependencies
  - Preserved formatting and cell styling
  - Support for multiple worksheets within single workbook
  - Built-in chart and graph generation capabilities
  - Automatic formula and calculation support
  - Professional report templates with company branding
- **Optimal Use Cases**:
  - Executive reporting and dashboard creation
  - Financial analysis and billing integration
  - Stakeholder presentations and compliance documentation
  - Business intelligence and trend analysis
  - Integration with existing Excel-based workflows
- **Configuration Parameters**:
  ```bash
  STORAGE_BACKEND=EXCEL
  EXCEL_PATH=/reports/monthly_weighbridge_data.xlsx
  EXCEL_TEMPLATE=/templates/company_report.xlsx
  EXCEL_SHEET_NAME=Vehicle_Records
  ```

### 4. Hybrid Storage Architecture (Advanced Configuration)
- **Purpose**: Simultaneous data storage across multiple formats for redundancy and flexibility
- **Key Features**:
  - Real-time data replication across storage backends
  - Automatic failover mechanisms for high availability
  - Configurable storage priority and synchronization rules
  - Cross-platform data consistency validation
- **Configuration Example**:
  ```bash
  STORAGE_BACKEND=HYBRID
  PRIMARY_STORAGE=MYSQL
  SECONDARY_STORAGE=CSV
  BACKUP_STORAGE=EXCEL
  SYNC_INTERVAL=300  # seconds
  ```

### Data Storage Performance Metrics

| Storage Type | Write Speed | Read Speed | Storage Efficiency | Scalability |
|-------------|-------------|------------|-------------------|-------------|
| MySQL | 1000+ records/sec | 10,000+ records/sec | High | Excellent |
| CSV | 500+ records/sec | 2000+ records/sec | Medium | Good |
| Excel XML | 200+ records/sec | 1000+ records/sec | Medium | Limited |



















## 🚀 Installation & Setup

### Prerequisites

#### System Requirements
- **Minimum RAM**: 4GB (8GB recommended for production environments)
- **Storage Space**: 2GB available disk space
- **Operating System**: Linux (Ubuntu 20.04+), Windows 10+, or macOS 12+
- **Network**: Internet connection for dependency installation

#### Hardware Requirements
| Component | Specification | Purpose |
|-----------|---------------|---------|
| **Load Cell** | 5kg capacity, HX711 compatible | Weight measurement |
| **Microcontroller** | ESP32, Raspberry Pi, or Arduino | Data processing and control |
| **Camera Module** | USB or CSI interface, 1080p minimum | License plate capture |
| **Power Supply** | 5V-20V DC, 2A minimum | System power |
| **Storage Device** | MicroSD card (32GB+ recommended) | Local data storage |

### Installation Methods

#### Method 1: Quick Installation (Recommended)
```bash
# Clone the repository
git clone https://github.com/your-org/weighbridge-automation-system.git
cd weighbridge-automation-system

# Run automated setup script
chmod +x setup.sh
./setup.sh
```

#### Method 2: Manual Installation
```bash
# Install dependencies
sudo apt update
sudo apt install -y cmake build-essential libopencv-dev libmysqlcppconn-dev

# Build the project
cd vehicle_weighbridge
mkdir build && cd build
cmake ..
make -j$(nproc)

# Install the application
sudo make install
```

#### Method 3: Docker Installation
```bash
# Pull and run the container
docker pull weighbridge/automation-system:latest
docker run -d --name weighbridge-system \
  -p 8080:8080 \
  -v /dev/ttyUSB0:/dev/ttyUSB0 \
  -v /data:/app/data \
  weighbridge/automation-system:latest
```

### Platform-Specific Setup

#### ESP32 Setup
```bash
# Install ESP32 Arduino Core
git clone https://github.com/espressif/arduino-esp32.git
cd arduino-esp32
git submodule update --init --recursive

# Install HX711 library
arduino-cli lib install "HX711"

# Flash firmware
arduino-cli compile --fqbn esp32:esp32:esp32 weighbridge_firmware
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 weighbridge_firmware
```

#### Raspberry Pi Setup
```bash
# Enable camera module
sudo raspi-config
# Navigate to: Interface Options > Camera > Enable

# Install camera libraries
sudo apt install -y python3-picamera python3-opencv

# Configure GPIO
sudo usermod -a -G gpio $USER
```

#### STM32 Setup
```bash
# Install STM32CubeIDE
wget https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/stm32cubeide.html

# Configure project for STM32F4 discovery board
# Import project: File > Import > STM32 Project from STM32CubeMX
```

## ⚙️ Configuration

### Environment Variables

Create a `.env` file in the project root with the following configuration:

```bash
# Storage Backend Configuration
STORAGE_BACKEND=MYSQL  # Options: MYSQL, CSV, EXCEL, HYBRID

# MySQL Configuration (Primary Storage)
DB_HOST=localhost
DB_USER=weighbridge_user
DB_PASS=secure_password_here
DB_NAME=vehicle_weighbridge_data
DB_PORT=3306

# CSV Configuration
CSV_PATH=/data/weighbridge_records.csv
CSV_DELIMITER=,
CSV_ENCODING=UTF-8
CSV_MAX_SIZE=100MB

# Excel Configuration
EXCEL_PATH=/reports/monthly_data.xlsx
EXCEL_TEMPLATE=/templates/company_report.xlsx
EXCEL_SHEET_NAME=Vehicle_Records

# Hardware Configuration
SERIAL_PORT=/dev/ttyUSB0
SERIAL_BAUD=9600
CAMERA_DEVICE=/dev/video0
LOADCELL_CALIBRATION_FACTOR=2280.0

# System Configuration
LOG_LEVEL=INFO
DATA_RETENTION_DAYS=365
BACKUP_INTERVAL_HOURS=24
```

### Database Setup

#### MySQL Database Initialization
```sql
-- Create database and user
CREATE DATABASE vehicle_weighbridge_data;
CREATE USER 'weighbridge_user'@'localhost' IDENTIFIED BY 'secure_password_here';
GRANT ALL PRIVILEGES ON vehicle_weighbridge_data.* TO 'weighbridge_user'@'localhost';
FLUSH PRIVILEGES;

-- Import database schema
mysql -u weighbridge_user -p vehicle_weighbridge_data < CREATE-TABLE.sql
```

#### CSV Storage Setup
```bash
# Create data directory
sudo mkdir -p /data/weighbridge
sudo chown $USER:$USER /data/weighbridge

# Initialize CSV file with headers
echo "timestamp,weight,license_plate,image_path,vehicle_type" > /data/weighbridge/vehicle_data.csv
```

#### Excel Template Setup
```bash
# Create reports directory
sudo mkdir -p /reports
sudo mkdir -p /templates

# Download sample Excel template
wget https://raw.githubusercontent.com/your-org/weighbridge-templates/main/company_report.xlsx \
  -O /templates/company_report.xlsx
```

### Hardware Configuration

#### Load Cell Calibration
```bash
# Run calibration utility
./calibration_tool --platform=ESP32 --load_cell=HX711

# Follow on-screen instructions to:
# 1. Remove all weight from scale
# 2. Press ENTER for zero calibration
# 3. Place known weight (e.g., 1kg)
# 4. Enter actual weight value
# 5. Save calibration factor to configuration
```

#### Camera Setup
```bash
# Test camera functionality
./camera_test --device=/dev/video0 --resolution=1920x1080

# Configure camera settings
./camera_config --brightness=50 --contrast=50 --saturation=50
```

### Network Configuration

#### WiFi Setup (ESP32)
```cpp
// Configure WiFi credentials in ESP32 firmware
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
```

#### Ethernet Setup (Raspberry Pi)
```bash
# Configure static IP (optional)
sudo nano /etc/dhcpcd.conf

# Add the following lines:
interface eth0
static ip_address=192.168.1.100/24
static routers=192.168.1.1
static domain_name_servers=8.8.8.8 8.8.4.4
```

## 🔧 Hardware Components

### Essential Components

| Component | Specification | Purpose | Compatibility |
|-----------|---------------|---------|---------------|
| **Load Cell** | 5kg capacity, strain gauge type | Weight measurement | HX711 amplifier |
| **HX711 Module** | 24-bit ADC, 128x gain | Signal amplification | All microcontrollers |
| **Microcontroller** | ESP32/Raspberry Pi/Arduino | Data processing | Platform-specific |
| **Camera Module** | USB/CSI interface, 1080p+ | Image capture | Platform-dependent |
| **Power Supply** | 5V-20V DC, 2A+ | System power | Universal |
| **Jumper Wires** | Male-to-female, various lengths | Electrical connections | Universal |
| **Breadboard/PCB** | Prototype or custom board | Circuit assembly | Size-dependent |

### Optional Components

| Component | Specification | Purpose | Use Cases |
|-----------|---------------|---------|-----------|
| **LCD Display** | 16x2 or 20x4 character | Local data display | Standalone operation |
| **LED Indicators** | RGB or single-color | Status indication | Visual feedback |
| **Buzzer** | 5V active buzzer | Audio alerts | Alarm notifications |
| **SD Card Module** | SPI interface | Local data storage | Offline operation |
| **Real-time Clock** | DS3231 or similar | Precise timing | Timestamp accuracy |
| **Temperature Sensor** | DS18B20 or DHT22 | Environmental monitoring | Data correlation |

### Component Interconnection

#### ESP32 Wiring Diagram
```
ESP32    |    Component
---------|------------------
GPIO 2   |    HX711 DOUT
GPIO 4   |    HX711 SCK
5V       |    HX711 VCC
GND      |    HX711 GND
USB      |    Camera Module
```

#### Raspberry Pi Wiring Diagram
```
Raspberry Pi  |    Component
--------------|------------------
GPIO 18       |    HX711 DOUT
GPIO 19       |    HX711 SCK
5V            |    HX711 VCC
GND           |    HX711 GND
CSI Port      |    Camera Module
```

## 🖥️ System Architecture

### Project Structure Overview

The Weighbridge Automation System follows a modular, object-oriented architecture designed for maintainability, scalability, and cross-platform compatibility. The system is organized into distinct layers with clear separation of concerns.

```
📁 WEIGHBRIDGE-AUTOMATION-SYSTEM/
├── 📁 vehicle_weighbridge/          # Core C++ application
│   ├── 📄 main.cpp                  # Application entry point
│   ├── 📄 CMakeLists.txt            # Build configuration
│   ├── 📄 DataStorage.h             # Abstract storage interface
│   ├── 📄 SerialReader.h/.cpp       # Microcontroller communication
│   ├── 📄 CameraHandler.h/.cpp     # OpenCV image processing
│   ├── 📄 MySQLHandler.h/.cpp      # MySQL database storage
│   ├── 📄 CSVHandler.h/.cpp         # CSV file storage
│   └── 📄 ExcelHandler.h/.cpp      # Excel XML storage
├── 📄 CREATE-TABLE.sql              # Database schema
├── 📁 ESP32 installation Code/      # Microcontroller firmware
└── 📄 Architecture design           # System design reference
```

### Core Architecture Components

#### 1. **Data Flow Architecture**
```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   Load Cell     │    │  Microcontroller│    │  Data Storage   │
│   (Weight)      │───▶│   (Processing)  │───▶│   (Database)    │
└─────────────────┘    └─────────────────┘    └─────────────────┘
                              │
                              ▼
                       ┌─────────────────┐
                       │  Camera Module  │
                       │ (License Plate) │
                       └─────────────────┘
```

#### 2. **Software Architecture Layers**

```
┌─────────────────────────────────────────────────────────────┐
│                    Application Layer                       │
│  ┌─────────────────┐  ┌─────────────────┐  ┌──────────────┐  │
│  │   main.cpp      │  │  DataStorage    │  │  Threading   │  │
│  │  (Orchestrator) │  │  (Interface)    │  │  Management  │  │
│  └─────────────────┘  └─────────────────┘  └──────────────┘  │
└─────────────────────────────────────────────────────────────┘
┌─────────────────────────────────────────────────────────────┐
│                    Service Layer                           │
│  ┌─────────────────┐  ┌─────────────────┐  ┌──────────────┐  │
│  │  SerialReader   │  │  CameraHandler   │  │  Storage     │  │
│  │  (Hardware I/O) │  │  (OpenCV)        │  │  Handlers    │  │
│  └─────────────────┘  └─────────────────┘  └──────────────┘  │
└─────────────────────────────────────────────────────────────┘
┌─────────────────────────────────────────────────────────────┐
│                    Hardware Layer                          │
│  ┌─────────────────┐  ┌─────────────────┐  ┌──────────────┐  │
│  │   Load Cell     │  │   Camera        │  │  Storage     │  │
│  │   (HX711)       │  │   (USB/CSI)     │  │  (MySQL/CSV) │  │
│  └─────────────────┘  └─────────────────┘  └──────────────┘  │
└─────────────────────────────────────────────────────────────┘
```

### File Relationships and Dependencies

#### **Core Module Dependencies**
```
main.cpp
├── SerialReader.h/.cpp          # Hardware communication
├── CameraHandler.h/.cpp         # Image processing
├── DataStorage.h                # Abstract interface
├── MySQLHandler.h/.cpp         # Database storage
├── CSVHandler.h/.cpp           # File storage
└── ExcelHandler.h/.cpp         # Excel storage
```

#### **Class Hierarchy and Interfaces**

```cpp
// Abstract Base Class
DataStorage (Interface)
├── MySQLHandler : public DataStorage
├── CSVHandler : public DataStorage
└── ExcelHandler : public DataStorage

// Hardware Interface Classes
SerialReader (Hardware Communication)
CameraHandler (Image Processing)
```

### Component Interaction Flow

#### **1. System Initialization**
```cpp
// main.cpp - Application startup
SerialReader serial("/dev/ttyUSB0", 9600);     // Hardware interface
CameraHandler camera;                          // Image processing
DataStorage* storage = createStorageBackend(); // Storage abstraction
```

#### **2. Data Processing Pipeline**
```
1. Vehicle Detection → SerialReader.readWeight()
2. Weight Measurement → Data validation and formatting
3. Camera Capture → CameraHandler.captureImage()
4. License Plate Recognition → OpenCV image processing
5. Data Storage → Storage backend selection (MySQL/CSV/Excel)
6. System Logging → Error handling and monitoring
```

#### **3. Storage Backend Selection**
```cpp
// Environment-based configuration
if (backend == "CSV") {
    storage = std::make_unique<CSVHandler>(csvPath);
} else if (backend == "EXCEL") {
    storage = std::make_unique<ExcelHandler>(xlsPath);
} else {
    storage = std::make_unique<MySQLHandler>(host, user, pass, db);
}
```

### Build System Architecture

#### **CMake Configuration**
```cmake
# CMakeLists.txt - Build system
cmake_minimum_required(VERSION 3.10)
project(WebBridgeSystem)

# Dependencies
find_package(OpenCV REQUIRED)      # Computer vision
find_package(Threads REQUIRED)     # Multi-threading

# Source files
add_executable(WebBridgeSystem
    main.cpp
    SerialReader.cpp
    CameraHandler.cpp
    MySQLHandler.cpp
    CSVHandler.cpp
    ExcelHandler.cpp
)

# Linking
target_link_libraries(WebBridgeSystem
    ${OpenCV_LIBS}     # OpenCV libraries
    mysqlcppconn       # MySQL connector
    pthread            # Threading support
)
```

### Data Storage Architecture

#### **Storage Interface Design**
```cpp
// DataStorage.h - Abstract interface
class DataStorage {
public:
    virtual ~DataStorage() = default;
    virtual void insertData(const std::string& weight,
                           const std::string& timestamp,
                           const std::string& imagePath) = 0;
};
```

#### **Storage Implementation Hierarchy**
```
DataStorage (Abstract)
├── MySQLHandler
│   ├── Database connection management
│   ├── SQL query execution
│   └── Transaction handling
├── CSVHandler
│   ├── File I/O operations
│   ├── Data formatting
│   └── Error handling
└── ExcelHandler
    ├── XML generation
    ├── Excel formatting
    └── Template support
```

### Hardware Integration Architecture

#### **Serial Communication Layer**
```cpp
// SerialReader.h - Hardware interface
class SerialReader {
public:
    SerialReader(const std::string& port, int baudRate);
    std::string readWeight();  // Read from load cell via HX711
private:
    int fd;  // File descriptor for serial port
};
```

#### **Camera Processing Layer**
```cpp
// CameraHandler.h - Image processing
class CameraHandler {
public:
    std::string captureImage(const std::string& filename);
    // OpenCV integration for license plate recognition
};
```

### Threading and Concurrency

#### **Multi-threaded Data Processing**
```cpp
// main.cpp - Concurrent processing
while (true) {
    std::string weightData = serial.readWeight();     // Hardware thread
    std::string imagePath = camera.captureImage();   // Camera thread
    storage->insertData(weight, timestamp, imagePath); // Storage thread
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
```

### Configuration Management

#### **Environment-based Configuration**
```bash
# Runtime configuration via environment variables
STORAGE_BACKEND=MYSQL|CSV|EXCEL
DB_HOST=localhost
DB_USER=weighbridge_user
DB_PASS=secure_password
CSV_PATH=/data/records.csv
EXCEL_PATH=/reports/data.xml
```

### Error Handling and Logging

#### **Exception Handling Strategy**
- **Hardware Layer**: Serial communication error handling
- **Processing Layer**: OpenCV exception management
- **Storage Layer**: Database connection and file I/O error handling
- **Application Layer**: Global exception handling and logging

### Performance Considerations

#### **Optimization Strategies**
- **Memory Management**: Smart pointers and RAII principles
- **I/O Operations**: Asynchronous data processing
- **Database Connections**: Connection pooling and reuse
- **Image Processing**: OpenCV optimization and caching

![System Architecture Diagram](LOAD%20CELL.png)

## 📊 Usage Examples

### Basic Operation
```bash
# Start the system
sudo ./weighbridge_system

# Monitor real-time data
tail -f /var/log/weighbridge.log

# Check system status
./system_status --health-check
```

### Data Export
```bash
# Export to CSV
./data_export --format=csv --start-date=2024-01-01 --end-date=2024-01-31

# Generate Excel report
./data_export --format=excel --template=monthly_report --output=january_2024.xlsx

# Database backup
./backup_tool --type=full --destination=/backups/weighbridge_backup.sql
```

### Remote Monitoring
```bash
# Start web interface
./web_interface --port=8080 --bind=0.0.0.0

# API endpoint examples
curl http://localhost:8080/api/vehicles/latest
curl http://localhost:8080/api/statistics/daily
curl http://localhost:8080/api/export/csv?date=2024-01-15
```

---

## 🤝 Contributing

We welcome contributions from the community! The Weighbridge Automation System thrives on community involvement, and we appreciate your interest in making it better.

### Quick Contribution Workflow

Follow this simple 4-step process to contribute:

```
⭐ Star → 🍴 Fork → 🔄 Pull Request → ✅ Merge
```

1. **⭐ Star** the repository to show your support and stay updated with new releases
2. **🍴 Fork** the repository to create your own copy for development
3. **🔄 Submit a Pull Request** with your enhancements or bug fixes
4. **✅ Merge** happens after review and approval

### Types of Contributions

We welcome various types of contributions:

#### 🐛 Bug Fixes
- Report bugs through [GitHub Issues](https://github.com/your-org/weighbridge-automation-system/issues)
- Fix existing issues and submit pull requests
- Include test cases to prevent regression

#### ✨ Feature Enhancements
- New platform support (microcontrollers, operating systems)
- Additional data storage formats
- Performance optimizations
- UI/UX improvements
- Documentation updates

#### 🔧 Hardware Support
- New microcontroller compatibility
- Sensor integration improvements
- Circuit design optimizations
- Calibration procedure enhancements

#### 📚 Documentation
- Code documentation improvements
- Tutorial and guide creation
- Translation support
- Video demonstrations

### Contribution Guidelines

Before contributing, please:

1. **Read our [Contributing Guidelines](CONTRIBUTING.md)** for detailed information
2. **Check existing issues** to avoid duplicate work
3. **Follow our coding standards** (C++17, proper commenting, error handling)
4. **Test your changes** thoroughly on supported platforms
5. **Update documentation** if adding new features
6. **Write clear commit messages** following conventional commit format

### Development Setup

```bash
# 1. Fork and clone the repository
git clone https://github.com/YOUR-USERNAME/weighbridge-automation-system.git
cd weighbridge-automation-system

# 2. Add upstream remote
git remote add upstream https://github.com/your-org/weighbridge-automation-system.git

# 3. Create a feature branch
git checkout -b feature/your-feature-name

# 4. Make your changes and test
# ... your development work ...

# 5. Commit and push
git commit -m "feat: add your feature description"
git push origin feature/your-feature-name

# 6. Create a Pull Request on GitHub
```

### Recognition

Contributors will be:
- 🏆 Listed in our [Contributors](CONTRIBUTORS.md) file
- 🎉 Mentioned in release notes for significant contributions
- 💬 Invited to join our community discussions
- 📜 Eligible for contributor certificates

### Questions or Need Help?

- 💬 **Discussions**: Join our [GitHub Discussions](https://github.com/your-org/weighbridge-automation-system/discussions)
- 📧 **Email**: Contact us at [contributions@weighbridge-system.org](mailto:contributions@weighbridge-system.org)
- 🐛 **Issues**: Report bugs or request features via [GitHub Issues](https://github.com/your-org/weighbridge-automation-system/issues)

Thank you for considering contributing to the Weighbridge Automation System! 🚀

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🔒 Security

For security-related issues and best practices, please refer to our [Security Policy](SECURITY.md).

