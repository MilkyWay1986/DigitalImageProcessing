#include "SIFT.h"


cv::Mat Sift(const cv::Mat &lhs, const cv::Mat &rhs) {

    cv::Ptr<cv::xfeatures2d::SiftFeatureDetector> featureDetector = cv::xfeatures2d::SiftFeatureDetector::create();
    cv::Ptr<cv::xfeatures2d::SiftDescriptorExtractor> featureExtractor = cv::xfeatures2d::SiftDescriptorExtractor::create();
    cv::BFMatcher matcher;

    //---------------------------------------------------------------------------------
    cv::Mat lhs_gray;
    cvtColor(lhs, lhs_gray, CV_BGR2GRAY);

    std::vector<cv::KeyPoint> lhs_points;
    lhs_points.reserve(lhs.cols * lhs.rows);

    cv::Mat lhs_description;

    featureDetector->detect(lhs_gray, lhs_points);
    featureExtractor->compute(lhs_gray, lhs_points, lhs_description);

    std::vector<cv::Mat> lhs_desc_collection(1, lhs_description);
    matcher.add(lhs_desc_collection);
    matcher.train();

    //---------------------------------------------------------------------------------
    cv::Mat rhs_gray;
    cvtColor(rhs, rhs_gray, CV_BGR2GRAY);

    std::vector<cv::KeyPoint> rhs_points;
    rhs_points.reserve(rhs.cols * rhs.rows);

    cv::Mat rhs_description;

    featureDetector->detect(rhs_gray, rhs_points);
    featureExtractor->compute(rhs_gray, rhs_points, rhs_description);

    //---------------------------------------------------------------------------------
    std::vector<std::vector<cv::DMatch> > neighbors;
    neighbors.reserve(std::max(lhs.cols * lhs.rows, rhs.cols * rhs.rows));

    matcher.knnMatch(rhs_description, neighbors, 2);

    std::vector<cv::DMatch> valid_neighbors;
    valid_neighbors.reserve(std::max(lhs.cols * lhs.rows, rhs.cols * rhs.rows));
    for (auto &neighbor : neighbors)
        if (neighbor[0].distance < 0.6 * neighbor[1].distance) valid_neighbors.emplace_back(neighbor[0]);

    cv::Mat sift;
    drawMatches(rhs, rhs_points, lhs, lhs_points, valid_neighbors, sift);

    return sift;
}