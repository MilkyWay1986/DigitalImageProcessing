#include <iostream>
#include "Morfology.h"

int main(int argc, char **argv) {

    try {
        cv::CommandLineParser parser(argc, argv, "{@image|2_1.png|}");


        cv::imshow("origin", cv::imread(parser.get<std::string>("@image"),
                                        cv::IMREAD_COLOR));
        Morfology(cv::imread(parser.get<std::string>("@image"),
                             cv::IMREAD_COLOR));


        cv::waitKey();

    } catch (...) {
        return -1;
    }

    return 0;
}
