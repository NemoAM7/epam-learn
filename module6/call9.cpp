#include<iostream>
using namespace std;

int main() {
	int a = 2, b = 3;
	auto op = [a, &b](int x) {return x * a + b;};
	cout << "op(5): " << op(5) << endl;
	b = 100;
	cout << "op(5) after b = 100: " << op(5) << endl;

	return 0;
}
