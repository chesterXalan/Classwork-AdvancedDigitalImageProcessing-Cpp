#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat image(Size(800, 800), CV_8UC3, Scalar(100, 50, 50));
	String windowName = "Window with Blank Image";

	namedWindow(windowName);
	imshow(windowName, image);

	waitKey(0);
	destroyWindow(windowName);
	return 0;
}