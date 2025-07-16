
// Handler for Microcontoller side readings
#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <string>

class SerialReader {
public:
    SerialReader(const std::string& port, int baudRate);
    std::string readWeight();

private:
    int fd;
};

#endif