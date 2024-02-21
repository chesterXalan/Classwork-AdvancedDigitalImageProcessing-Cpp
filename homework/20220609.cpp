#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat image = imread("images/12345.png");
	Mat new_image = Mat::zeros(image.size(), image.type());
	double alpha = 0.5;
	int betaNum = 10;
	Vec3b intensity;

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			intensity = image.at<Vec3b>(y, x);
			new_image.at<Vec3b>(y, x)[0] = alpha * intensity.val[0] + betaNum;
			new_image.at<Vec3b>(y, x)[1] = alpha * intensity.val[1] + betaNum;
			new_image.at<Vec3b>(y, x)[2] = alpha * intensity.val[2] + betaNum;
		}
	}

	imshow("Original Image", image);
	imshow("New Image", new_image);
	waitKey();
	return 0;
}