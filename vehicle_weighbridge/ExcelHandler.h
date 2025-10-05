#ifndef EXCELHANDLER_H
#define EXCELHANDLER_H

#include "DataStorage.h"
#include <fstream>
#include <mutex>
#include <string>

// Writes Excel 2003 XML (SpreadsheetML) so Excel can open it directly
class ExcelHandler : public DataStorage {
public:
    explicit ExcelHandler(const std::string& filePath);
    ~ExcelHandler();

    void insertData(const std::string& weight,
                    const std::string& timestamp,
                    const std::string& imagePath) override;

private:
    std::string xmlFilePath;
    std::ofstream outputStream;
    std::mutex writeMutex;
    bool headerWritten;
    bool footerWritten;

    void writeHeader();
    void writeFooter();
    static std::string escapeXml(const std::string& value);
};

#endif


