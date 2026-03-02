#include<iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
	return a + b;
}

int main() {
	int i = add(2, 3);
	double d = add(2.1, 3.9);
	float f = add(11.5f, 2.5f);

	cout << "int : " << i << endl;
	cout << "double : " << d << endl;
	cout << "float : " << f << endl;

}