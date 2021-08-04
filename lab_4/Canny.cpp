#include "Canny.h"

cv::Mat CannyOpenCV(const cv::Mat &src) {

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::Mat canny(src.rows, src.cols, cv::DataType<uchar>::type);

    cv::Canny(src2, canny, 10, 100, 3, true);

    return canny;
}