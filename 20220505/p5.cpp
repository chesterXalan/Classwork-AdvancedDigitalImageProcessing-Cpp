#include <tuple>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

tuple<int, int> divide(int dividend, int divisor) {
	auto pa1 = dividend / divisor;
	auto pa2 = dividend % divisor;

	return make_tuple(pa1, pa2);
}

int main() {
	int quotient, remainder;
	tie(quotient, remainder) = divide(14, 3);

	cout << quotient << endl;
	cout << remainder << endl;
	
	waitKey(0);
	return 0;
}