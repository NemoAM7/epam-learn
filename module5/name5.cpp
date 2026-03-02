#include<iostream>
using namespace std;

template<typename T>
class Box {
	T value;
public:
	Box(T v) : value(v) {}

	void print() const {
		cout << value << endl;
	}
};

int main() {
	Box<int> intBox(42);
	Box<string> strBox("Hello, templates!");
	intBox.print();
	strBox.print();
}