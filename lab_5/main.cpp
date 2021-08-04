#include "Moravec.h"
#include "Harris.h"
#include "FFD.h"

int main(int argc, char **argv) {

    cv::CommandLineParser parser(argc, argv, "{@image|1.png|}");

    cv::imshow("original", cv::imread(parser.get<std::string>("@image"),
                                      cv::IMREAD_COLOR));

//****************************************************************************************//
    cv::imshow("Moravec", Moravec(cv::imread(parser.get<std::string>("@image"),
                                             cv::IMREAD_COLOR), 3, 500));
//****************************************************************************************//
    Harris(cv::imread(parser.get<std::string>("@image"),
                      cv::IMREAD_COLOR), 200);
//****************************************************************************************//

    Fast(cv::imread(parser.get<std::string>("@image"),
                    cv::IMREAD_COLOR));
//****************************************************************************************//


    cv::waitKey();

    return 0;
}