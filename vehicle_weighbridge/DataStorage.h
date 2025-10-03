// Common storage interface to allow pluggable backends (MySQL, CSV, etc.)
#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <string>

class DataStorage {
public:
    virtual ~DataStorage() = default;

    // Persist a single record consisting of weight, timestamp, and image path
    virtual void insertData(const std::string& weight,
                            const std::string& timestamp,
                            const std::string& imagePath) = 0;
};

#endif


