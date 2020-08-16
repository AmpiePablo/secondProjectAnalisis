#pragma once
#ifndef ROADLIMIT_H
#define ROADLIMIT_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace cv;
using namespace std;

class RoadLimit {
private:
	string road;
	int thresh ;
	int max_thresh = 255;
	Mat src;
	Mat src_gray;
	RNG rng;// = rng();
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

public:

	RoadLimit() {
		road = "pista.jpg";
		thresh = 100;
		max_thresh = 255;
		rng = 12345;
	}

    void readImage() {
        src = imread(road);

        /// Convert image to gray and blur it
        cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
        blur(src_gray, src_gray, Size(3, 3));

        /// Create Window
       // namedWindow("imagen", cv::WINDOW_AUTOSIZE);
        //imshow("imagen", src);

        //thresh_callback(0,0);

        waitKey(0);
    }
    bool verifyArea(int x, int y) {
        double res = thresh_callback(0, 0, x, y);
        if (res == 1) {
            return true;
        }
        return false;
    }

    int thresh_callback(int, void*, double x, double y)
    {
        

        /// Detect edges using canny
        Canny(src_gray, canny_output, thresh, thresh * 2, 3);
        /// Find contours
        findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

        int result = pointPolygonTest(contours[0], Point2f(x,y), false);
        return result;
    }
};

#endif // ! ROADLIMIT_HPP

