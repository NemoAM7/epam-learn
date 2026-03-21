#include<iostream>
using namespace std;

int main() {
	auto add = [](int a, int b) {return a + b;};
	int result = add(5 , 10);
	cout << "Sum: " << result << endl;
	return 0;
}