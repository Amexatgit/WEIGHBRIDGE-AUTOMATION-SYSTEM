#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include "DataStorage.h"
#include <fstream>
#include <mutex>
#include <string>

class CSVHandler : public DataStorage {
public:
    explicit CSVHandler(const std::string& filePath);
    ~CSVHandler();

    void insertData(const std::string& weight,
                    const std::string& timestamp,
                    const std::string& imagePath) override;

private:
    std::string csvFilePath;
    std::ofstream outputStream;
    std::mutex writeMutex;
    bool hasHeader;

    void ensureOpen();
    void writeHeaderIfNeeded();
    static std::string escapeCsv(const std::string& field);
};

#endif


