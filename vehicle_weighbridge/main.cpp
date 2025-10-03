// I think we shall work differently on diffrent modules of the system so i have divide it into parts
// we will combine every component handler at the end of development into main 
// For now i have completed OpenCV module completly i was workinjg on it quiet long
#include "SerialReader.h"
#include "CameraHandler.h"
#include "MySQLHandler.h"
#include "CSVHandler.h"
#include "ExcelHandler.h"
#include "DataStorage.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstdlib>

int main() {
    SerialReader serial("/dev/ttyUSB0", 9600);
    CameraHandler camera;

    const char* backendEnv = std::getenv("STORAGE_BACKEND");
    std::string backend = backendEnv ? std::string(backendEnv) : std::string("MYSQL");

    std::unique_ptr<DataStorage> storage;
    if (backend == "CSV") {
        const char* csvPathEnv = std::getenv("CSV_PATH");
        std::string csvPath = csvPathEnv ? std::string(csvPathEnv) : std::string("vehicle_data.csv");
        storage = std::make_unique<CSVHandler>(csvPath);
        std::cout << "Using CSV storage at: " << csvPath << std::endl;
    } else if (backend == "EXCEL") {
        const char* xlsPathEnv = std::getenv("EXCEL_PATH");
        std::string xlsPath = xlsPathEnv ? std::string(xlsPathEnv) : std::string("vehicle_data.xml");
        storage = std::make_unique<ExcelHandler>(xlsPath);
        std::cout << "Using Excel XML storage at: " << xlsPath << std::endl;
    } else {
        const char* host = std::getenv("DB_HOST");
        const char* user = std::getenv("DB_USER");
        const char* pass = std::getenv("DB_PASS");
        const char* db   = std::getenv("DB_NAME");
        std::string hostStr = host ? host : "localhost";
        std::string userStr = user ? user : "root";
        std::string passStr = pass ? pass : "yourpassword";
        std::string dbStr   = db   ? db   : "vehicle_data";
        storage = std::make_unique<MySQLHandler>(hostStr, userStr, passStr, dbStr);
        std::cout << "Using MySQL storage at host: " << hostStr << ", db: " << dbStr << std::endl;
    }

    while (true) {
        std::string weightData = serial.readWeight();
        if (!weightData.empty()) {
            std::cout << "Weight: " << weightData << std::endl;

            std::string imagePath = camera.captureImage("opencv_image.jpg");
            std::string timestamp = std::to_string(std::time(nullptr));

            storage->insertData(weightData, timestamp, imagePath);

            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
}

    