#include "Sobel.h"
#include "Laplas.h"
#include "Laplacian_of_Gaussian.h"
#include "Canny.h"


int main(int argc, char **argv) {

    cv::CommandLineParser parser(argc, argv, "{@image|ellipses.jpg|}");

    cv::imshow("original", cv::imread(parser.get<std::string>("@image"),
                                      cv::IMREAD_COLOR));

//****************************************************************************************//
    cv::imshow("Sobel", Sobel(cv::imread(parser.get<std::string>("@image"),
                                         cv::IMREAD_COLOR)));

    cv::imshow("SobelOpenCV", SobelOpenCV(cv::imread(parser.get<std::string>("@image"),
                                                     cv::IMREAD_COLOR)));
//****************************************************************************************//

//****************************************************************************************//
    cv::imshow("Laplas", Laplas(cv::imread(parser.get<std::string>("@image"),
                                           cv::IMREAD_COLOR)));

    cv::imshow("LaplasOpenCV", LaplasOpenCV(cv::imread(parser.get<std::string>("@image"),
                                                       cv::IMREAD_COLOR)));
//****************************************************************************************//

//****************************************************************************************//
    cv::imshow("LaplacianOfGaussian", LaplacianOfGaussian(
            cv::imread(parser.get<std::string>("@image"),
                       cv::IMREAD_COLOR)));

    cv::imshow("LaplacianOfGaussianOpenCV", LaplacianOfGaussianOpenCV(
            cv::imread(parser.get<std::string>("@image"),
                       cv::IMREAD_COLOR)));
//****************************************************************************************//

//****************************************************************************************//
    cv::imshow("CannyOpenCV", CannyOpenCV(
            cv::imread(parser.get<std::string>("@image"),
                       cv::IMREAD_COLOR)));
//****************************************************************************************//

    cv::waitKey();

    return 0;
}