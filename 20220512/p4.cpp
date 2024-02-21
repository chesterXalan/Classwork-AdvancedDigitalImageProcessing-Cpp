#include <iostream>
#include <algorithm>
#include <omp.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define ARRAY_SIZE 10000000
#define ARRAY_VALUE 1231

int main() {
	double time00 = static_cast<double>(getTickCount());

	int* arr = new int[ARRAY_SIZE];
	fill_n(arr, ARRAY_SIZE, ARRAY_VALUE);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = arr[i] / arr[i] + arr[i] / 5 - 14;
	}

	double time01 = (static_cast<double>(getTickCount()) - time00) /
					getTickFrequency();
	cout << "(No openmp) time = " << time01 << " second" << endl;

	double time1 = static_cast<double>(getTickCount());
	omp_set_num_threads(4);

	int* arr2 = new int[ARRAY_SIZE]; 
	fill_n(arr2, ARRAY_SIZE, ARRAY_VALUE);
	#pragma omp parallel for //openMP
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arr2[i] = arr2[i] / arr2[i] + arr2[i] / 5 - 14;
	}
	double time2 = (static_cast<double>(getTickCount()) - time1) /
					getTickFrequency();
	cout << "(openmp) time = " << time2 << " second" << endl;

	return 0;
}