#include<iostream>
using namespace std;

int main() {
	int counter = 0;
	auto inc = [counter]() mutable {counter++;};
	inc();
	cout << "After inc() (by value) counter = " << counter << endl;

	auto incRef = [&counter]() mutable {counter++;};
	incRef();
	cout << "After infRef() (by reference) counter = " << counter << endl;

	return 0;
}