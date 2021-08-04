#pragma once

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

#include <cmath>
#include <vector>


cv::Mat Moravec(const cv::Mat &, int, std::size_t);

