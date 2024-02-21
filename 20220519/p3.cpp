#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; using namespace std;
int main(int argc, char* argv[]) {
	VideoCapture cap("images/2012_0728_AP_188_Taipei.mp4");
	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per seconds : " << fps << endl;
	Mat frame;

	while (true)
	{
		bool bSuccess = cap.read(frame);
		if (bSuccess == false) {
			cout << "Found the end of the video" << endl;
			break;
		}
		else {
			imshow("My First Video", frame);
			if (waitKey(10) == 27) {
				cout << "Esc key is pressed by user. \
					Stoppig the video" << endl;
				break;
			}
		}
	}
	return 0;
}