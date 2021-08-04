#include "Morfology.h"


void Morfology(const cv::Mat &src) {
    /*
     * 1. Размыкание
        2. Замыкание
        3. Условную дилатацию
        4. Морфологический скелет по Lantuéjoul.
     * */

    cv::Mat src2(src.rows, src.cols, cv::DataType<uchar>::type);
    cvtColor(src, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);

    cv::Mat gauss(src.rows, src.cols, cv::DataType<uchar>::type);

    cv::GaussianBlur(src2,
                     gauss,
                     cv::Size(3, 3),
                     3
    );

    cv::Mat otsy;
    cv::threshold(gauss, otsy, 100.0, 255, cv::THRESH_BINARY);
    cv::imshow("otsy", otsy);


    cv::Mat erode, dilate;
    cv::Mat element = getStructuringElement(cv::MORPH_CROSS, cv::Size(4, 4));
    cv::Mat element2 = getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));

    //-----------------------------------------------------------------------------------------------
    cv::Mat opening;
    cv::erode(otsy, erode, element, cv::Point(-1, -1), 1);
    cv::dilate(erode, opening, element2, cv::Point(-1, -1), 3);
    cv::imshow("opening", opening);
    //-----------------------------------------------------------------------------------------------
    cv::Mat closing;
    cv::dilate(otsy, dilate, element2, cv::Point(-1, -1), 7);
    cv::erode(dilate, closing, element, cv::Point(-1, -1), 3);
    cv::imshow("closing", closing);
    //-----------------------------------------------------------------------------------------------
    cv::Mat erode_element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 2));
    cv::Mat dilate_element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 4));

    cv::Mat eroded, dilated, before, same, difference;
    cv::erode(otsy, eroded, erode_element);

    bool flag = true;

    while (flag) {
        before = otsy;
        cv::dilate(eroded, dilated, dilate_element);
        cv::bitwise_and(dilated, otsy, same);
        cv::subtract(same, before, difference);
        auto zeros = cv::countNonZero(difference);
        if (zeros == 0) flag = false;
        eroded = same;
    }
    cv::imshow("Conditional build-up", eroded);
    //-----------------------------------------------------------------------------------------------

    cv::Mat img = cv::imread("2_2.png", 0);
    cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
    cv::Mat skel(img.size(), CV_8UC1, cv::Scalar(0));
    cv::Mat temp;
    cv::Mat _eroded;

    cv::Mat _element = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3,3));

    bool done;
    do
    {
        cv::erode(img, _eroded, _element);
        cv::dilate(_eroded, temp, _element);
        cv::subtract(img, temp, temp);
        cv::bitwise_or(skel, temp, skel);
        _eroded.copyTo(img);

        done = (cv::countNonZero(img) == 0);
    } while (!done);

    cv::imshow("Skeleton", skel);
    cv::waitKey(0);
}




