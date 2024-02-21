#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; using namespace std;
int main(int argc, char** argv) {
	Mat image = imread("images/12345.png");

	Mat imageBrighnessHigh30, imageBrighnessHigh100,
		imageBrighnessLow60, imageBrighnessLow100;
	image.convertTo(imageBrighnessHigh30, -1, 1, 30);
	image.convertTo(imageBrighnessLow60, -1, 1, -60);

	String windowNameOriginalImage = "Original Image";
	String windowNameBrightnessHigh30 = "Brightness Increased by 30";
	String windowNameBrightnessLow60 = "Brightness Decreased by 60";

	imshow(windowNameOriginalImage, image);
	imshow(windowNameBrightnessHigh30, imageBrighnessHigh30);
	imshow(windowNameBrightnessLow60, imageBrighnessLow60);
	waitKey(0);
	
	return 0;
	}