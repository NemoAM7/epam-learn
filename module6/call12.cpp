#include<iostream>
using namespace std;
int main() {
	auto multiply = [](int x, int factor = 2) {return x * factor;};
	cout << "multiply(10) :" << multiply(10) << endl;
	cout << "multiply(10, 5) : " << multiply(10, 5) << endl;

	return 0;
}