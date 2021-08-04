#include "Bredly.h"


void Bredly(const cv::Mat &src_) {

    cv::Mat src2(src_.rows, src_.cols, cv::DataType<uchar>::type);
    cvtColor(src_, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);


    uchar *src = static_cast<uchar *> (src2.data);
    uchar *res = static_cast<uchar *> (src2.data);


    int height = src2.rows;
    int width = src2.cols;

    const int S = width / 8;
    int s2 = S / 2;
    const double t = 0.15;
    long sum = 0;
    int count = 0;
    int index;
    int x1, y1, x2, y2;
    std::shared_ptr<ulong *> integral_image = std::make_shared<ulong *>(new ulong[width * height * sizeof(ulong *)]);

    for (auto i = 0; i < width; i++) {
        sum = 0;
        for (auto j = 0; j < height; j++) {
            index = j * width + i;
            sum += src[index];
            if (i == 0) (*integral_image)[index] = sum;
            else (*integral_image)[index] = (*integral_image)[index - 1] + sum;
        }
    }


    for (auto i = 0; i < width; i++) {
        for (auto j = 0; j < height; j++) {
            index = j * width + i;

            x1 = i - s2;
            x2 = i + s2;
            y1 = j - s2;
            y2 = j + s2;

            if (x1 < 0) x1 = 0;
            if (x2 >= width) x2 = width - 1;
            if (y1 < 0) y1 = 0;
            if (y2 >= height) y2 = height - 1;

            count = (x2 - x1) * (y2 - y1);

            sum = (*integral_image)[y2 * width + x2] - (*integral_image)[y1 * width + x2] -
                  (*integral_image)[y2 * width + x1] + (*integral_image)[y1 * width + x1];

            if (static_cast<long> (src[index] * count) < static_cast<long> (sum * (1.0 - t))) res[index] = 0;
            else res[index] = 255;
        }
    }


    auto Ss = src2.size();
    cv::Mat bradley(Ss.height, Ss.width, CV_8UC1, res, 0);
    cv::imshow("Bradley", bradley);
}

