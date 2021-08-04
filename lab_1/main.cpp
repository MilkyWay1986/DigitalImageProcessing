#include "Gauss.h"



int main(int argc, char **argv) {

    cv::CommandLineParser parser(argc, argv, "{@image|ellipses.jpg|}");

    cv::imshow("FiltrGauss", FiltrGauss(cv::imread(parser.get<std::string>("@image"),
                                              cv::IMREAD_COLOR)));

    cv::imshow("FiltrGaussOpenCV", FiltrGaussOpenCV(cv::imread(parser.get<std::string>("@image"),
                                              cv::IMREAD_COLOR)));
    cv::waitKey();
    return 0;
}
