#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv) {
	Mat image = imread("images/12345.png");
	cvtColor(image, image, COLOR_BGR2GRAY);

	Mat hist_equalized_image;
	equalizeHist(image, hist_equalized_image);

	imshow("Original Image", image);
	imshow("Histogram Equalized Image", hist_equalized_image);
	waitKey(0);
	destroyAllWindows();
	
	return 0;
}