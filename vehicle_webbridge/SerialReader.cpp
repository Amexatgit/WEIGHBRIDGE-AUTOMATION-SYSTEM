#include "SerialReader.h"    // microcontroller done 
#include <fcntl.h>
#include <termios.h>  
#include <unistd.h>
#include <iostream>

SerialReader::SerialReader(const std::string& port, int baudRate) {
    fd = open(port.c_str(), O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Serial open failed");
        exit(1);
    }

    struct termios tty{};
    tcgetattr(fd, &tty);
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tcsetattr(fd, TCSANOW, &tty);
}

std::string SerialReader::readWeight() {
    char buf[100];
    int n = read(fd, buf, sizeof(buf));
    if (n > 0) return std::string(buf, n);
    return "";
}
