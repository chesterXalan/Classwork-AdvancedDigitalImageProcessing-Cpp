#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std; using namespace cv;
void main() {
	Mat img = imread("images/681212.jpg"); imshow("original Image", img);
	Mat img_gray; cvtColor(img, img_gray, COLOR_BGR2GRAY);
	Mat img_blur;

	GaussianBlur(img_gray, img_blur, Size(3, 3), 0);
	Mat sobelx, sobely, sobelxy;

	Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);
	Sobel(img_blur, sobely, CV_64F, 0, 1, 5);
	Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);
	imshow("Sobel X", sobelx); imshow("Sobel Y", sobely);
	imshow("Sobel XY using Sobel() function", sobelxy);

	Mat edges;
	Canny(img_blur, edges, 100, 200, 3, false);
	imshow("Canny edge detection", edges);
	waitKey(0);
}