#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat src, dst;
	src = imread("images/12345.png");
	
	int element_size = 3;
	int s = element_size * 2 + 1;
	Mat structureElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));

	dilate(src, dst, structureElement, Point(-1, -1), 1);
	erode(src, dst, structureElement);

	imshow("input image", src);
	imshow("output image", dst);
	waitKey(0);
	return 0;
}