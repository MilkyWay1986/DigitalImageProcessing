#include "Laplas.h"

//**************************************************************************//
cv::Mat Laplas(const cv::Mat &src) {

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::Mat laplas(src.rows, src.cols, cv::DataType<uchar>::type);


    int laplace_mask[9] = {0, -1, 0, -1, 4, -1, 0, -1, 0};
    std::size_t iter_array = 0;
    int val = 0;


    for (auto y = 1; y < src2.rows - 1; ++y) {
        for (auto x = 1; x < src2.cols - 1; ++x) {

            for (auto k = y - 1; k < y + 2; ++k) {
                for (auto l = x - 1; l < x + 2; ++l) {
                    val += laplace_mask[iter_array] * static_cast<int>(src2.at<uchar>(k, l));
                    iter_array++;
                }
            }

            if (val < 0) val = 0;
            if (val > 255) val = 255;

            laplas.at<uchar>(y - 1, x - 1) = val;
            val = 0;
            iter_array = 0;
        }
    }
    return laplas;
}
//**************************************************************************//
cv::Mat LaplasOpenCV(const cv::Mat &src) {

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::Mat laplas(src.rows, src.cols, cv::DataType<uchar>::type);

    cv::Laplacian(src2, laplas, CV_8U);

    return laplas;
}
//**************************************************************************//