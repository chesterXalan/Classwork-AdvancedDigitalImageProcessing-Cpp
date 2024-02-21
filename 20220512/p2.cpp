#include <iostream>
#include <tuple>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

tuple<Mat, int> medianBlurBoLin(Mat srcImage, int sizeuse) {
	Mat dstImage;
	medianBlur(srcImage, dstImage, sizeuse);
	if (sizeuse >= 3) {
		cout << "Okay" << endl;
	}

	return make_tuple(dstImage, sizeuse);
}

int main() {
	int index;
	Mat srcImage = imread("images/100098.jpg");
	Mat dstImage;

	tie(dstImage, index) = medianBlurBoLin(srcImage, 3);
	imshow("Original image", srcImage);
	imshow("Median Blurring", dstImage);

	waitKey(0);
	destroyAllWindows();
}