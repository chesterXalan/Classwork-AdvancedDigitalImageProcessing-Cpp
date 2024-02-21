#include <iostream>
#include <tuple>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat medianBlurBoLin(Mat srcImage, int sizeuse) {
	Mat dstImage;
	medianBlur(srcImage, dstImage, sizeuse);

	return dstImage;
}

int main() {
	Mat srcImage = imread("images/100098.jpg");
	Mat dstImage = medianBlurBoLin(srcImage, 3);

	imshow("Original image", srcImage);

	imshow("Median Blurring", dstImage);

	waitKey(0);
	destroyAllWindows();
}