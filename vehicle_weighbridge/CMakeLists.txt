 cmake_minimum_required(VERSION 3.10)
project(WebBridgeSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(WebBridgeSystem
    main.cpp
    SerialReader.cpp
    CameraHandler.cpp
    MySQLHandler.cpp
    CSVHandler.cpp
    ExcelHandler.cpp
)

target_link_libraries(WebBridgeSystem
    ${OpenCV_LIBS}
    mysqlcppconn
    pthread
)
