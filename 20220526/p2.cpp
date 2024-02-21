#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; using namespace std;
int main(int argc, char** argv) {
	Mat image = imread("images/12345.png");

	Mat imageBrighnessHigh40, imageBrighnessHigh100,
		imageBrighnessLow60, imageBrighnessLow100;
	image.convertTo(imageBrighnessHigh40, -1, 1, 40);
	image.convertTo(imageBrighnessLow60, -1, 1, -60);

	String windowNameOriginalImage = "Original Image";
	String windowNameBrightnessHigh40 = "Brightness Increased by 40";
	String windowNameBrightnessLow60 = "Brightness Decreased by 60";

	imshow(windowNameOriginalImage, image);
	imshow(windowNameBrightnessHigh40, imageBrighnessHigh40);
	imshow(windowNameBrightnessLow60, imageBrighnessLow60);
	waitKey(0);

	return 0;
}