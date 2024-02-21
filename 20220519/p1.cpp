#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat image = imread("images/3854141.png");
	Mat img1(Size(200, 200), CV_16UC3);
	String windowName = "The Image";

	namedWindow(windowName);
	imshow(windowName, img1);

	waitKey(0);
	destroyWindow(windowName);
	return 0;
}