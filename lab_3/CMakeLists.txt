cmake_minimum_required(VERSION 3.17)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_FOUND 1)

find_package(OpenCV REQUIRED)

add_executable(lab_3 main.cpp Morfology.h Morfology.cpp)

target_link_libraries(lab_3 ${OpenCV_LIBS})

