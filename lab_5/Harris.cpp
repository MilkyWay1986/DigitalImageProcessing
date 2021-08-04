#include "Harris.h"

cv::Mat Harris(const cv::Mat &src, std::size_t threshold) {


    cv::Mat src2(src.rows, src.cols, CV_32FC1);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);


    cv::Mat dst, dst_norm, dst_norm_scaled;
    dst = cv::Mat::zeros(src.size(), CV_32FC1);


    cv::cornerHarris(src2, dst, 7, 5, 0.05, cv::BORDER_DEFAULT);


    cv::normalize(dst, dst_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
    cv::convertScaleAbs(dst_norm, dst_norm_scaled);


    for (auto y = 0; y < dst_norm.rows; ++y) {
        for (auto x = 0; x < dst_norm.cols; ++x) {
            if (static_cast<int> (dst_norm.at<double>(y, x)) > threshold) {
                circle(src, cv::Point(x, y), 5,
                       cv::Scalar(0), 2, 8, 0);
            }
        }
    }


    cv::imshow("Harris", dst_norm_scaled);

    return dst_norm_scaled;
}
