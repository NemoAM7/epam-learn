#include<iostream>
using namespace std;

int main() {
	int x = 10;
	int* ptr = &x;
	auto p = ptr;
	auto& r = x;

	r = 20;

	*p = 30;

	cout << "x = " << x << endl;
	cout << "*p = " << *p << endl;
	cout << "r = " << r << endl;

	return 0;
}