// I think we shall work differently on diffrent modules of the system so i have divide it into parts
// we will combine every component handler at the end of development into main 
// For now i have completed OpenCV module completly i was workinjg on it quiet long
#include "SerialReader.h"
#include "CameraHandler.h"
#include "MySQLHandler.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

int main() {
    SerialReader serial("/dev/ttyUSB0", 9600);
    CameraHandler camera;
   MySQLHandler db("localhost", "root", "yourpassword", "vehicle_data");

    while (true) {
              std::string weightData = serial.readWeight();
              if (!weightData.empty()) {
               std::cout << "Weight: " << weightData << std::endl;

             std::string imagePath = camera.captureImage("opencv_image.jpg");
             std::string timestamp = std::to_string(std::time(nullptr));

             db.insertData(weightData, timestamp, imagePath);

            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
}

    