#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
	Mat srcImage, dstImage;
	srcImage = imread("images/12345.png");
	imshow("Original image", srcImage);
	blur(srcImage, dstImage, Size(9, 9));

	imshow("Averaging", dstImage);
	waitKey(0);
}