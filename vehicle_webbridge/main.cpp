#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

#include <opencv2/opencv.hpp>

#include <iostream>


int main() {
    // im building this code for opencv 
    // im reffering a youtube toutorial about opencv to learn how things work 
    cv::Mat image(200, 400, CV_8UC3, cv::Scalar(0, 255, 0));
    cv::putText(image, "OpenCV OK", {50, 100}, cv::FONT_HERSHEY_SIMPLEX, 1, {0,0,0}, 2);
    cv::imwrite("test_opencv.jpg", image);
    std::cout << "Image saved using OpenCV.\n";
}