#include "Gauss.h"

cv::Mat FiltrGauss(const cv::Mat &src) {

    cv::Mat gauss(src.rows, src.cols, cv::DataType<uchar>::type);
    cv::Mat temp(src.rows, src.cols, cv::DataType<uchar>::type);

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::imshow("original", src);
    cv::imshow("grey", src2);


    int lenMask = 3;
    for (auto y = 0; y < src.rows; ++y)
        for (auto x = 0; x < src.cols; ++x)
            temp.at<uchar>(y + 1, x + 1) = src2.at<uchar>(y, x);


    int mask[lenMask * lenMask];
    mask[0] = mask[2] = mask[6] = mask[8] = 1;
    mask[1] = mask[3] = mask[5] = mask[7] = 2;
    mask[4] = 4;

    int denominatore = 0;
    for (int i = 0; i < lenMask * lenMask; i++) denominatore += mask[i];

    int value[lenMask * lenMask];
    for (auto y = 1; y < src.rows; ++y) {
        for (auto x = 1; x < src.cols; ++x) {
            value[0] = temp.at<uchar>(y - 1, x - 1) * mask[0];
            value[1] = temp.at<uchar>(y - 1, x) * mask[1];
            value[2] = temp.at<uchar>(y - 1, x + 1) * mask[2];
            value[3] = temp.at<uchar>(y, x - 1) * mask[3];
            value[4] = temp.at<uchar>(y, x) * mask[4];
            value[5] = temp.at<uchar>(y, x + 1) * mask[5];
            value[6] = temp.at<uchar>(y + 1, x - 1) * mask[6];
            value[7] = temp.at<uchar>(y + 1, x) * mask[7];
            value[8] = temp.at<uchar>(y + 1, x + 1) * mask[8];

            int avg = 0;
            for (auto i = 0; i < lenMask * lenMask; ++i) avg += value[i];
            avg = avg / denominatore;

            gauss.at<uchar>(y, x) = avg;
        }
    }
    return gauss;
}

cv::Mat FiltrGaussOpenCV(const cv::Mat &src) {

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);
    cv::Mat gauss(src.rows, src.cols, cv::DataType<uchar>::type);

    cv::GaussianBlur(src2,
                     gauss,
                     cv::Size(3, 3),
                     3
    );

    return gauss;
}