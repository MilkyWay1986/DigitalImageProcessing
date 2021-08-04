#include "Moravec.h"

cv::Mat Moravec(const cv::Mat &src, int kSize, std::size_t threshold) {


    cv::Mat src2 = src;
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::Mat moravec = src;

    auto r = static_cast<int>(kSize / 2);


    //auto *v_points = new cv::Point[src.rows * src.cols];
    std::vector<cv::Point> v_points;
    v_points.reserve(src2.rows * src2.cols);
    std::size_t iter_vector_points = 0;

    for (auto y = r; y < src2.rows - r; ++y) {
        for (auto x = r; x < src2.cols - r; ++x) {
            int wV1, wV2, wV3, wV4;
            wV1 = wV2 = wV3 = wV4 = 0;


            // horizontal
            for (auto k = -r; k <= r; ++k) {
                for (auto m = -r; m <= r; ++m) {
                    //Judging whether it crosses the boundary during the movement, if it crosses the boundary, skip the current loop to avoid errors
                    int a = y + k;
                    int b = x + m + 1;
                    if (b >= src2.cols) continue;

                    wV1 += (src2.at<uchar>(y + k, x + m + 1) - src2.at<uchar>(y + k, x + m))
                           * (src2.at<uchar>(y + k, x + m + 1) - src2.at<uchar>(y + k, x + m));
                }
            }


            // vertical
            for (auto k = -r; k <= r; ++k) {
                for (auto m = -r; m <= r; ++m) {
                    int a = y + k + 1;
                    int b = x + m;
                    if (a >= src2.rows) continue;

                    wV2 += (src2.at<uchar>(y + k + 1, x + m) - src2.at<uchar>(y + k, x + m))
                           * (src2.at<uchar>(y + k + 1, x + m) - src2.at<uchar>(y + k, x + m));
                }
            }


            // 45
            for (auto k = -r; k <= r; ++k) {
                for (auto m = -r; m <= r; ++m) {
                    int a = y + k + 1;
                    int b = x + m + 1;
                    if (a >= src2.rows || b >= src2.cols) continue;

                    wV3 += (src2.at<uchar>(y + k + 1, x + m + 1) - src2.at<uchar>(y + k, x + m))
                           * (src2.at<uchar>(y + k + 1, x + m + 1) - src2.at<uchar>(y + k, x + m));
                }
            }


            // 135
            for (auto k = -r; k <= r; ++k) {
                for (auto m = -r; m <= r; ++m) {
                    int a = y + k + 1;
                    int b = x + m - 1;
                    if (a >= src2.rows || b < 0) continue;

                    wV4 += (src2.at<uchar>(a, b) - src2.at<uchar>(y + k, x + m))
                           * (src2.at<uchar>(a, b) - src2.at<uchar>(y + k, x + m));
                }
            }


            int value = std::min(std::min(wV1, wV2), std::min(wV3, wV4));

            if (value > threshold) {
                v_points[iter_vector_points] = cv::Point(x, y);
                iter_vector_points++;
            }
        }
    }

    for (auto i = 0; i < iter_vector_points; ++i)
        circle(moravec, v_points[i],
               0, cv::Scalar(0, 255, 0));

    return moravec;
}

