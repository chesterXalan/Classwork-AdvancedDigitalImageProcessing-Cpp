#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string a = "There is no spoon.";
	cout << a << endl;

	string* b = &a;
	cout << b << endl;

	string* d = new string("There is no spoon.");
	cout << d << endl;

	return 0;
}