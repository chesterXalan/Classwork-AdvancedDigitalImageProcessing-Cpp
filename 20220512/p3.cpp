#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	double time00 = static_cast<double>(getTickCount());
	for (size_t i = 0; i < 10000000; i++) {

	}
	double time01 = (static_cast<double>(getTickCount()) - time00)
					/ getTickFrequency();
	cout << "time = " << time01 << " second" << endl;
	return 0;
}