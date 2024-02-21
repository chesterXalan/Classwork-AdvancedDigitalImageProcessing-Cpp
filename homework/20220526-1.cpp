#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; using namespace std;
int main(int argc, char** argv) {
	Mat image = imread("images/12345.png");
	Mat hist_equalized_image; vector<Mat> vec_channels;
	cvtColor(image, hist_equalized_image, COLOR_BGR2HSV);
	split(hist_equalized_image, vec_channels);
	equalizeHist(vec_channels[2], vec_channels[2]);
	merge(vec_channels, hist_equalized_image);

	cvtColor(hist_equalized_image, hist_equalized_image, COLOR_HSV2BGR);
	imshow("Original Image", image);
	imshow("Histogram Equalized Color Image", hist_equalized_image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}