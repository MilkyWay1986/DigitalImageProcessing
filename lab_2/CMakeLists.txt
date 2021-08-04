cmake_minimum_required(VERSION 3.17)
project(lab_2)

set(CMAKE_CXX_STANDARD 17)
set(OpenCV_FOUND 1)

find_package(OpenCV REQUIRED)

add_executable(lab_2 main.cpp Otsy.h Otsy.cpp Bredly.h Bredly.cpp)

target_link_libraries(lab_2 ${OpenCV_LIBS})