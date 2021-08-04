cmake_minimum_required(VERSION 3.19)

project(lab_6)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_FOUND 1)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++17 -Wall -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -OPENCV_ENABLE_NONFREE")

find_package(OpenCV REQUIRED)

add_executable(lab_6 main.cpp SIFT.h SIFT.cpp)

target_link_libraries(lab_6 ${OpenCV_LIBS})