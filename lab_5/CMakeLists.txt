cmake_minimum_required(VERSION 3.17)

project(lab_5)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_FOUND 1)

find_package(OpenCV REQUIRED)

add_executable(lab_5 main.cpp Moravec.h Moravec.cpp Harris.h Harris.cpp FFD.h FFD.cpp)

target_link_libraries(lab_5 ${OpenCV_LIBS})