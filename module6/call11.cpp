#include<iostream>
using namespace std;

int main() {
	int counter = 0;
	auto next = [counter]() mutable {
		counter++;
		return counter;
		};

	cout << "next(): " << next() << endl;
	cout << "next(): " << next() << endl;
	cout << "next(): " << next() << endl;
	
	cout << "Outer counter: " << counter << endl;
	
	return 0;
}