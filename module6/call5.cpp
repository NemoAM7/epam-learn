#include<iostream>
using namespace std;

struct Add {
	int operator()(int a, int b) const { return a + b; }
};

int main() {
	Add add;
	int result = add(10, 20);
	cout << "Sum: " << result << endl;
	return 0;
}