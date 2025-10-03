#include "ExcelHandler.h"
#include <filesystem>

ExcelHandler::ExcelHandler(const std::string& filePath)
    : xmlFilePath(filePath), headerWritten(false), footerWritten(false) {
    // Open stream in append mode to allow continued writing across runs
    outputStream.open(xmlFilePath, std::ios::app);
    // If the file is new (size 0), write header
    if (!std::filesystem::exists(xmlFilePath) || std::filesystem::file_size(xmlFilePath) == 0) {
        writeHeader();
    } else {
        headerWritten = true;
    }
}

ExcelHandler::~ExcelHandler() {
    std::lock_guard<std::mutex> guard(writeMutex);
    writeFooter();
    if (outputStream.is_open()) {
        outputStream.flush();
        outputStream.close();
    }
}

void ExcelHandler::writeHeader() {
    if (headerWritten) return;
    outputStream << "<?xml version=\"1.0\"?>\n";
    outputStream << "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n";
    outputStream << " xmlns:o=\"urn:schemas-microsoft-com:office:office\"\n";
    outputStream << " xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n";
    outputStream << " xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\">\n";
    outputStream << " <Worksheet ss:Name=\"VehicleData\">\n";
    outputStream << "  <Table>\n";
    // Header row
    outputStream << "   <Row>\n";
    outputStream << "    <Cell><Data ss:Type=\"String\">weight</Data></Cell>\n";
    outputStream << "    <Cell><Data ss:Type=\"String\">timestamp</Data></Cell>\n";
    outputStream << "    <Cell><Data ss:Type=\"String\">image_path</Data></Cell>\n";
    outputStream << "   </Row>\n";
    headerWritten = true;
}

void ExcelHandler::writeFooter() {
    if (footerWritten) return;
    if (!headerWritten) return;
    outputStream << "  </Table>\n";
    outputStream << " </Worksheet>\n";
    outputStream << "</Workbook>\n";
    footerWritten = true;
}

std::string ExcelHandler::escapeXml(const std::string& value) {
    std::string out;
    out.reserve(value.size());
    for (char c : value) {
        switch (c) {
            case '&': out += "&amp;"; break;
            case '<': out += "&lt;"; break;
            case '>': out += "&gt;"; break;
            case '"': out += "&quot;"; break;
            case '\'': out += "&apos;"; break;
            default: out.push_back(c); break;
        }
    }
    return out;
}

void ExcelHandler::insertData(const std::string& weight,
                              const std::string& timestamp,
                              const std::string& imagePath) {
    std::lock_guard<std::mutex> guard(writeMutex);
    if (!headerWritten) writeHeader();

    outputStream << "   <Row>\n";
    outputStream << "    <Cell><Data ss:Type=\"String\">" << escapeXml(weight) << "</Data></Cell>\n";
    outputStream << "    <Cell><Data ss:Type=\"String\">" << escapeXml(timestamp) << "</Data></Cell>\n";
    outputStream << "    <Cell><Data ss:Type=\"String\">" << escapeXml(imagePath) << "</Data></Cell>\n";
    outputStream << "   </Row>\n";
    outputStream.flush();
}


