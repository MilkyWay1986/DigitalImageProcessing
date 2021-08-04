#pragma once

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>


cv::Mat Laplas(const cv::Mat &);

cv::Mat LaplasOpenCV(const cv::Mat &);