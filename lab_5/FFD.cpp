#include "FFD.h"


cv::Mat Fast(const cv::Mat &src){

    cv::Mat src2(src.rows, src.cols, CV_32FC1);
    cv::Mat fast(src.rows, src.cols, CV_32FC1);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    std::vector<cv::KeyPoint> v_points;
    v_points.reserve(src2.cols * src2.rows);

    cv::FAST(src2, v_points, 80, false);
    drawKeypoints(src2, v_points, fast);
    cv::imshow("FFD", fast);
    return fast;
}
