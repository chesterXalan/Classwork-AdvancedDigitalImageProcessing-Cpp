#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	Mat img = imread("images/3854141.png", -1);
	if (img.empty()) return -1;

	namedWindow("test", WINDOW_AUTOSIZE);
	imshow("test", img);

	waitKey(0);
	destroyWindow("test");

	return 0;
}