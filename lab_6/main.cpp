#include "SIFT.h"

int main(int argc, char **argv) {

    cv::CommandLineParser parser1(argc, argv, "{@image|1.jpg|}");
    cv::CommandLineParser parser2(argc, argv, "{@image|2.jpg|}");

    cv::imshow("original_lhs", cv::imread(parser1.get<std::string>("@image"),
                                          cv::IMREAD_COLOR));
    cv::imshow("original_rhs", cv::imread(parser2.get<std::string>("@image"),
                                          cv::IMREAD_COLOR));

//****************************************************************************************//


     cv::imshow("sift", Sift(cv::imread(parser1.get<std::string>("@image"),
                                        cv::IMREAD_COLOR),
                             cv::imread(parser2.get<std::string>("@image"),
                                        cv::IMREAD_COLOR)));

//*****************************************************************************************//


    cv::waitKey();

    return 0;
}