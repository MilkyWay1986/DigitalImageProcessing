#pragma once

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

#include<map>

//******************************************************************//

cv::Mat FiltrGaussOpenCV(const cv::Mat &);

//******************************************************************//

cv::Mat Otsy(const cv::Mat &);

std::pair<int, std::map<int, int>> Calculate(const cv::Mat &);

double CalcBestThresh(const cv::Mat &src, std::size_t);

//******************************************************************//

cv::Mat OtsyOpenCV(const cv::Mat &);

//******************************************************************//
