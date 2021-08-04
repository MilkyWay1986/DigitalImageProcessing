#pragma once

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

#include <cmath>




cv::Mat Sobel(const cv::Mat &);

cv::Mat SobelOpenCV(const cv::Mat &);