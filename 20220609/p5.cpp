#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void main() {
	Mat img = imread("images/12345.png");

	Mat cropped_image = img(Range(25, 280), Range(55, 220)); // row, col

	imshow(" Original", img);
	imshow("Cropped", cropped_image);

	waitKey(0);
}