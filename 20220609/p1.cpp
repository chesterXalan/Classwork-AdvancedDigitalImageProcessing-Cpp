#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("images/12345.png");
	Mat new_image = Mat::zeros(image.size(), image.type());
	double alpha = 2.0;
	int betaNum = 5;

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < image.channels(); c++) {
				new_image.at<Vec3b>(y, x)[c] = 
					saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + betaNum);
			}
		}
	}

	imshow("Original Image", image);
	imshow("New Image", new_image);
	waitKey();
	return 0;
}