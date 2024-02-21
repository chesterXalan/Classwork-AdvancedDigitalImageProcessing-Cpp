#include <iostream>

using namespace std;

int main(void) {
	int n = 11;
	cout << n << endl;

	int* nPter = &n;
	cout << nPter << endl;

	int t = *nPter;
	cout << t << endl;

	return 0;
}