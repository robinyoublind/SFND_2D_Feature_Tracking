#ifndef matching2D_hpp
#define matching2D_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include "dataStructures.h"


std::vector<double> detKeypointsHarris(std::vector<cv::KeyPoint> &keypoints,int &numOfKpts, cv::Mat &img, std::vector<double> detectorTimes, bool bVis=false);
std::vector<double> detKeypointsShiTomasi(std::vector<cv::KeyPoint> &keypoints,int &numOfKpts, cv::Mat &img, std::vector<double> detectorTimes, bool bVis=false);
std::vector<double> detKeypointsFast(std::vector<cv::KeyPoint> &keypoints,int &numOfKpts, cv::Mat &img, std::vector<double> detectorTimes, bool bVis=false);
std::vector<double> detKeypointsBrisk(std::vector<cv::KeyPoint> &keypoints,int &numOfKpts, cv::Mat &img, std::vector<double> detectorTimes, bool bVis=false);
std::vector<double> detKeypointsOrb(std::vector<cv::KeyPoint> &keypoints,int &numOfKpts, cv::Mat &img, std::vector<double> detectorTimes, bool bVis=false);
std::vector<double> detKeypointsAkaze(std::vector<cv::KeyPoint> &keypoints,int &numOfKpts, cv::Mat &img, std::vector<double> detectorTimes, bool bVis=false);
std::vector<double> detKeypointsSift(std::vector<cv::KeyPoint> &keypoints, int &numOfKpts, cv::Mat &img, std::vector<double> detectorTimes, bool bVis=false);

std::vector<double> descKeypoints(std::vector<double> descritporTimes, std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, cv::Mat &descriptors, std::string descriptorType);
void matchDescriptors(std::vector<cv::KeyPoint> &kPtsSource, std::vector<cv::KeyPoint> &kPtsRef, cv::Mat &descSource, cv::Mat &descRef,
                      std::vector<cv::DMatch> &matches,std::string descriptorCategory, std::string descriptorType, std::string matcherType, std::string selectorType);

#endif /* matching2D_hpp */
