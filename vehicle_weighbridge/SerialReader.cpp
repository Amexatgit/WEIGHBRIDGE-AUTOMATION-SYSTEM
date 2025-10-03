#include "SerialReader.h"    // microcontroller done 
#include <fcntl.h>
#include <termios.h>  
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <dirent.h>

namespace {
    // Try common Linux device names. Prefer Raspberry Pi aliases first.
    std::vector<std::string> getCandidatePorts() {
        return {
            "/dev/serial0",   // RPi alias (preferred)
            "/dev/ttyAMA0",   // RPi PL011 UART
            "/dev/ttyS0",     // miniUART or SoC UART
            "/dev/ttyUSB0",   // USB-serial adapters
            "/dev/ttyUSB1",
            "/dev/ttyACM0",   // CDC ACM devices (e.g., some boards)
            "/dev/ttyACM1"
        };
    }

    bool fileExists(const std::string& path) {
        return access(path.c_str(), F_OK) == 0;
    }

    // Also scan /dev for matching prefixes when fixed candidates fail
    std::string scanDevByPrefixes(const std::vector<std::string>& prefixes) {
        DIR* dir = opendir("/dev");
        if (!dir) return "";
        std::string found;
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            std::string name = entry->d_name;
            for (const auto& prefix : prefixes) {
                if (name.rfind(prefix.substr(5), 0) == 0) { // compare after "/dev/"
                    found = std::string("/dev/") + name;
                    closedir(dir);
                    return found;
                }
            }
        }
        closedir(dir);
        return "";
    }

    speed_t baudToSpeed(int baudRate) {
        switch (baudRate) {
            case 50: return B50;
            case 75: return B75;
            case 110: return B110;
            case 134: return B134;
            case 150: return B150;
            case 200: return B200;
            case 300: return B300;
            case 600: return B600;
            case 1200: return B1200;
            case 1800: return B1800;
            case 2400: return B2400;
            case 4800: return B4800;
            case 9600: return B9600;
            case 19200: return B19200;
            case 38400: return B38400;
            case 57600: return B57600;
            case 115200: return B115200;
            case 230400: return B230400;
            default: return B9600;
        }
    }

    std::string autoDetectPort() {
        // 1) Try prioritized list
        for (const auto& candidate : getCandidatePorts()) {
            if (fileExists(candidate)) return candidate;
        }
        // 2) Fallback scan of /dev for common serial device families
        std::string fromScan = scanDevByPrefixes({
            "/dev/ttyUSB", "/dev/ttyACM", "/dev/ttyAMA", "/dev/ttyS"
        });
        return fromScan;
    }
}

SerialReader::SerialReader(const std::string& port, int baudRate) {
    std::string resolvedPort = port;
    if (resolvedPort.empty() || resolvedPort == "auto") {
        resolvedPort = autoDetectPort();
        if (resolvedPort.empty()) {
            std::cerr << "No serial device found. Specify a port explicitly." << std::endl;
            exit(1);
        }
        std::cout << "Auto-detected serial port: " << resolvedPort << std::endl;
    }

    fd = open(resolvedPort.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd < 0) {
        perror("Serial open failed");
        exit(1);
    }

    struct termios tty{};
    if (tcgetattr(fd, &tty) != 0) {
        perror("tcgetattr failed");
        exit(1);
    }

    // Set baud rate
    speed_t speed = baudToSpeed(baudRate);
    cfsetospeed(&tty, speed);
    cfsetispeed(&tty, speed);

    // 8N1, no flow control, local mode, enable receiver
    tty.c_cflag &= ~PARENB;            // no parity
    tty.c_cflag &= ~CSTOPB;            // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;                // 8 bits
    tty.c_cflag &= ~CRTSCTS;           // no HW flow control
    tty.c_cflag |= (CLOCAL | CREAD);   // local connection, enable receiver

    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // raw input
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);         // no SW flow control
    tty.c_oflag &= ~OPOST;                          // raw output

    // Read returns as soon as at least 1 byte is available, with ~0.5s timeout
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 5; // 0.5s (in deciseconds)

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("tcsetattr failed");
        exit(1);
    }

    // Clear O_NONBLOCK after configuring timeouts to allow VTIME to work as expected
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags & ~O_NONBLOCK);
}

std::string SerialReader::readWeight() {
    // Read a line or current buffer
    std::string data;
    char buf[256];
    ssize_t n = read(fd, buf, sizeof(buf));
    if (n > 0) {
        data.assign(buf, buf + n);
        // If the device sends lines, return up to newline
        std::size_t pos = data.find('\n');
        if (pos != std::string::npos) {
            return data.substr(0, pos);
        }
        return data;
    }
    return "";
}
