#include "Sobel.h"


//**************************************************************************//
cv::Mat Sobel(const cv::Mat &src) {

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::Mat gauss(src.rows, src.cols, cv::DataType<uchar>::type);
    cv::Mat otsy(src.rows, src.cols, cv::DataType<uchar>::type);
    cv::Mat sobel(src.rows, src.cols, cv::DataType<uchar>::type);


    cv::GaussianBlur(src2,
                     gauss,
                     cv::Size(3, 3),
                     3
    );

    cv::threshold(gauss, otsy, 100.0, 255, cv::THRESH_BINARY);


    int sobel_x[3][3] =
            {{-1, 0, 1},
             {-2, 0, 2},
             {-1, 0, 1}};

    int sobel_y[3][3] =
            {{-1, -2, -1},
             {0,  0,  0},
             {1,  2,  1}};

    for (auto x = 1; x < src2.cols - 1; ++x) {
        for (auto y = 1; y < src2.rows - 1; ++y) {

            auto pixel_x = (sobel_x[0][0] * otsy.at<uchar>(src2.cols * (y - 1) + (x - 1)))
                           + (sobel_x[0][1] * otsy.at<uchar>(src2.cols * (y - 1) + x))
                           + (sobel_x[0][2] * otsy.at<uchar>(src2.cols * (y - 1) + (x + 1)))
                           + (sobel_x[1][0] * otsy.at<uchar>(src2.cols * y + (x - 1)))
                           + (sobel_x[1][1] * otsy.at<uchar>(src2.cols * y + x))
                           + (sobel_x[1][2] * otsy.at<uchar>(src2.cols * y + (x + 1)))
                           + (sobel_x[2][0] * otsy.at<uchar>(src2.cols * (y + 1) + (x - 1)))
                           + (sobel_x[2][1] * otsy.at<uchar>(src2.cols * (y + 1) + x))
                           + (sobel_x[2][2] * otsy.at<uchar>(src2.cols * (y + 1) + (x + 1)));

            auto pixel_y = (sobel_y[0][0] * otsy.at<uchar>(src2.cols * (y - 1) + (x - 1)))
                           + (sobel_y[0][1] * otsy.at<uchar>(src2.cols * (y - 1) + x))
                           + (sobel_y[0][2] * otsy.at<uchar>(src2.cols * (y - 1) + (x + 1)))
                           + (sobel_y[1][0] * otsy.at<uchar>(src2.cols * y + (x - 1)))
                           + (sobel_y[1][1] * otsy.at<uchar>(src2.cols * y + x))
                           + (sobel_y[1][2] * otsy.at<uchar>(src2.cols * y + (x + 1)))
                           + (sobel_y[2][0] * otsy.at<uchar>(src2.cols * (y + 1) + (x - 1)))
                           + (sobel_y[2][1] * otsy.at<uchar>(src2.cols * (y + 1) + x))
                           + (sobel_y[2][2] * otsy.at<uchar>(src2.cols * (y + 1) + (x + 1)));

            int val = static_cast<int> (std::sqrt((std::pow(pixel_x, 2)) + (std::pow(pixel_y, 2))));

            if (val <= 0) val = 0;
            if (val > 255) val = 255;

            sobel.at<uchar>(src2.cols * y + x) = val;
        }
    }
    return sobel;
}

//**************************************************************************//
cv::Mat SobelOpenCV(const cv::Mat &src) {

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::Mat gauss(src.rows, src.cols, cv::DataType<uchar>::type);
    cv::Mat otsy(src.rows, src.cols, cv::DataType<uchar>::type);
    cv::Mat sobel(src.rows, src.cols, cv::DataType<uchar>::type);


    cv::GaussianBlur(src2,
                     gauss,
                     cv::Size(3, 3),
                     3
    );

    cv::threshold(gauss, otsy, 100.0, 255, cv::THRESH_BINARY);
    cv::Sobel(otsy, sobel, CV_8U, 1, 1);

    return sobel;
}
//**************************************************************************//