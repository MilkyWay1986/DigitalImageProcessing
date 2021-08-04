cmake_minimum_required(VERSION 3.17)
project(lab_1)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_FOUND 1)

find_package(OpenCV REQUIRED)


add_executable(lab_1 main.cpp   Gauss.cpp Gauss.h )

target_link_libraries(lab_1 ${OpenCV_LIBS})