#include "CSVHandler.h"
#include <filesystem>

CSVHandler::CSVHandler(const std::string& filePath)
    : csvFilePath(filePath), hasHeader(false) {
    ensureOpen();
    writeHeaderIfNeeded();
}

CSVHandler::~CSVHandler() {
    if (outputStream.is_open()) {
        outputStream.flush();
        outputStream.close();
    }
}

void CSVHandler::ensureOpen() {
    if (outputStream.is_open()) return;

    bool fileExists = std::filesystem::exists(csvFilePath);
    outputStream.open(csvFilePath, std::ios::app);
    hasHeader = fileExists;
}

void CSVHandler::writeHeaderIfNeeded() {
    if (!hasHeader && outputStream.is_open()) {
        outputStream << "weight,timestamp,image_path" << '\n';
        outputStream.flush();
        hasHeader = true;
    }
}

std::string CSVHandler::escapeCsv(const std::string& field) {
    bool needsQuotes = field.find(',') != std::string::npos ||
                       field.find('"') != std::string::npos ||
                       field.find('\n') != std::string::npos ||
                       field.find('\r') != std::string::npos;
    if (!needsQuotes) return field;

    std::string escaped;
    escaped.reserve(field.size() + 2);
    escaped.push_back('"');
    for (char c : field) {
        if (c == '"') escaped.push_back('"');
        escaped.push_back(c);
    }
    escaped.push_back('"');
    return escaped;
}

void CSVHandler::insertData(const std::string& weight,
                            const std::string& timestamp,
                            const std::string& imagePath) {
    std::lock_guard<std::mutex> guard(writeMutex);
    ensureOpen();
    writeHeaderIfNeeded();
    outputStream << escapeCsv(weight) << ','
                 << escapeCsv(timestamp) << ','
                 << escapeCsv(imagePath) << '\n';
    outputStream.flush();
}


