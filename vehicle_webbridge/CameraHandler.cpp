
//New approche for OpenCV

#include "CameraHandler.h"
#include <opencv2/opencv.hpp>
#include <stdexcept>

std::string CameraHandler::captureImage(const std::string& filename) {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        throw std::runtime_error("Unable to open webcam");
    }

    cv::Mat frame;
    cap >> frame;
    cv::imwrite(filename, frame);
    return filename;
}
