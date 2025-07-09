cmake_minimum_required(VERSION 3.10)
project(vehicle_webbridge)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(Threads REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(/usr/include/mysql)

add_executable(vehicle_webbridge main.cpp)

target_link_libraries(vehicle_webbridge 
    ${OpenCV_LIBS} 
    mysqlcppconn 
    Boost::system 
    pthread
)
