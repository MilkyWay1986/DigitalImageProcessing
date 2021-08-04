#pragma once

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
/*
 * http://aco.ifmo.ru/el_books/image_processing/7_02.html
 * */

#include <string>

cv::Mat FiltrGauss(const cv::Mat &);

cv::Mat FiltrGaussOpenCV(const cv::Mat &);