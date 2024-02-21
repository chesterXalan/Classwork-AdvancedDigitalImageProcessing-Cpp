#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; using namespace std;
int main(int argc, char* argv) {
	Mat image = imread("images/12345.png");
	bool isSuccess = imwrite("images/MyImage.jpg", image);
	cout << "Image is succusfully saved to a file" << endl;

	imshow("The Saved Image", image);
	waitKey(0);
	return 0;
}