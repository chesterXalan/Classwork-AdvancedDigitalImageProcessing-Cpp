#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat srcImage, dstImage;
	srcImage = imread("images/12345.png");
	imshow("Original image", srcImage);
	bilateralFilter(srcImage, dstImage, 20, 30, 30);

	imshow("Averaging", dstImage);
	waitKey(0);
}