#include "Otsy.h"
#include "Bredly.h"
#include <string>

int main(int argc, char **argv) {

    try {
        cv::CommandLineParser parser(argc, argv, "{@image|ellipses.jpg|}");

        cv::imshow("orig",
                   cv::imread(parser.get<std::string>("@image"),
                              cv::IMREAD_COLOR));

        cv::imshow("Otsy",
                   Otsy(cv::imread(parser.get<std::string>("@image"),
                                   cv::IMREAD_COLOR)));

        cv::imshow("OtsyOpenCV",
                   OtsyOpenCV(cv::imread(parser.get<std::string>("@image"),
                                         cv::IMREAD_COLOR)));


                Bredly(cv::imread(parser.get<std::string>("@image"),
                                  cv::IMREAD_COLOR));

        cv::waitKey();

    } catch (...) {
        return -1;
    }

    return 0;
}
