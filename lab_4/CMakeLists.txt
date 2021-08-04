cmake_minimum_required(VERSION 3.17)
project(lab_4)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_FOUND 1)

find_package(OpenCV REQUIRED)

add_executable(lab_4 main.cpp Sobel.h Sobel.cpp Laplas.h Laplas.cpp Laplacian_of_Gaussian.h Laplacian_of_Gaussian.cpp Canny.h Canny.cpp)

target_link_libraries(lab_4 ${OpenCV_LIBS})