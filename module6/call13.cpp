#include<iostream>
#include<functional>
using namespace std;

auto makeLambda() {
	int temp = 5;
	// BAD: capturing local by reference!
	return [&temp]() { return temp * 2; }; // Lambda holds a reference to a local
}

int main() { 
	auto lambda = makeLambda();
	cout << "Calling lambda after temp is gone!" << lambda() << endl; // Undefined behavior! garbage value printed due to a dangling refernce of temp variable 
	return 0;
}