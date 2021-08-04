#pragma once

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>


cv::Mat LaplacianOfGaussian(const cv::Mat &);

cv::Mat LaplacianOfGaussianOpenCV(const cv::Mat &);