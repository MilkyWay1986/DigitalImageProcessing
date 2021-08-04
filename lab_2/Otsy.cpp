#include "Otsy.h"
#include <iostream>

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

//**************************************************************************//

cv::Mat OtsyOpenCV(const cv::Mat &src) {
    cv::Mat otsy;
    cv::threshold(FiltrGaussOpenCV(src), otsy, 100.0, 255, cv::THRESH_BINARY);
    return otsy;
}

//**************************************************************************//

cv::Mat Otsy(const cv::Mat &src) {

    auto src2 = FiltrGaussOpenCV(src);
    cv::Mat otsy(src.rows, src.cols, cv::DataType<uchar>::type);

    double thresh = CalcBestThresh(src2, src2.rows * src2.cols);

    for (auto y = 0; y < src2.rows; ++y) {
        for (auto x = 0; x < src2.cols; ++x) {
            if (src2.at<uchar>(y, x) < thresh)
                otsy.at<uchar>(y, x) = 0;
            else
                otsy.at<uchar>(y, x) = 255;
        }
    }


    return otsy;
}


std::pair<int, std::map<int, int>> Calculate(const cv::Mat &src) {

    std::map<int, int> m;
    int sum = 0;

    for (auto y = 0; y < src.rows; ++y) {
        for (auto x = 0; x < src.cols; ++x) {
            ++m[src.at<uchar>(y, x)];
            sum += src.at<uchar>(y, x);
        }
    }

    return std::make_pair(sum, m);
}


double CalcBestThresh(const cv::Mat &src, const std::size_t size) {

    auto[all_intensity_sum, hist] = std::move(Calculate(src));

    auto all_pixel_count = size;


    int best_thresh = 0;
    double best_sigma = 0.0;

    int first_class_pixel_count = 0;
    int first_class_intensity_sum = 0;


    for (auto thresh = 0; thresh < 255; ++thresh) {

        first_class_pixel_count += hist[thresh];
        first_class_intensity_sum += thresh * hist[thresh];

        double first_class_prob = first_class_pixel_count / static_cast<double>(all_pixel_count);
        double second_class_prob = 1.0 - first_class_prob;

        double first_class_mean = first_class_intensity_sum / static_cast<double>(first_class_pixel_count);
        double second_class_mean = (all_intensity_sum - first_class_intensity_sum)
                                   / static_cast<double>(all_pixel_count - first_class_pixel_count);

        double mean_delta = first_class_mean - second_class_mean;

        double sigma = first_class_prob * second_class_prob * mean_delta * mean_delta;

        if (sigma > best_sigma) {
            best_sigma = sigma;
            best_thresh = thresh;
        }

    }

    return best_thresh;
}
//**************************************************************************//

