#pragma once

#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include <vector>
#include <cmath>

cv::Mat Sift(const cv::Mat &, const cv::Mat &);
