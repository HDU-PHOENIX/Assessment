#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
int main()
{
    Mat srcimage = imread("./assets/src.jpg");
    Mat result = imread("./assets/result.jpg");
    Mat dstimage;
    pyrDown(srcimage, srcimage);
    pyrDown(srcimage, srcimage);
    imshow("srcimage", srcimage);
    cvtColor(srcimage, dstimage, COLOR_RGB2GRAY);
    blur(dstimage, dstimage, Size(3, 3));
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(7, 7));
    morphologyEx(dstimage, dstimage, MORPH_CLOSE, element);
    threshold(dstimage, dstimage, 200, 255, THRESH_BINARY);
    imshow("threshold", dstimage);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dstimage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    vector<vector<Point>> poly(contours.size());
    approxPolyDP(Mat(contours[0]), poly[0], 3, true);
    Mat newimage;
    vector<Point2f> dst_corners(4);
    dst_corners[0] = Point2f(0, 0);
    dst_corners[1] = Point2f(500, 0);
    dst_corners[2] = Point2f(0, 950);
    dst_corners[3] = Point2f(500, 950);
    vector<Point2f> src_corners(4);
    src_corners[0] = poly[0][0];
    src_corners[2] = poly[0][1];
    src_corners[3] = poly[0][2];
    src_corners[1] = poly[0][3];
    Mat tansform = getPerspectiveTransform(src_corners, dst_corners);
    warpPerspective(srcimage, newimage, tansform, Size(500, 950), INTER_LINEAR);
    imshow("final", newimage);
    waitKey(0);
}