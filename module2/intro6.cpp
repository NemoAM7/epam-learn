#include<iostream>

using namespace std;

class Counter {
public:
	static int count;

	Counter() {
		count++;
	}

	static int getCount() {
		return count;
	}

	~Counter() {
		count--;
	}
};

void addCounters() {
	// c1 c2 created count incremented by 2
	Counter c1;
	Counter c2;

	cout << "Count: " << Counter::getCount() << endl; 

	// c3 c4 created count incremented by 2
	Counter c3;
	Counter c4;

	cout << "Count: " << Counter::getCount() << endl;
} // c1 c2 c3 c4 destroyed count decrmented by 4

int Counter::count = 0; // Initialize the static member variable

int main() {

	// count incremented by 4
	addCounters();
	// count deceremented by 4

	Counter c1; // c1 created count incremented by 1

	cout << "Count: " << Counter::getCount() << endl; 
} // c1 destroyed count decremented by 1