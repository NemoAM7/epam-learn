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

template<>
class Box<string> {
	string value;
public:
	Box(string v) : value(move(v)) {}

	void print() const {
		for (char c : value) {
			cout << static_cast<char>(toupper(static_cast<unsigned char>(c)));
		}
		cout << endl;
	}
};

int main() {
	Box<int> intBox(42);
	Box<string> strBox("Hello, templates!");
	intBox.print();
	strBox.print();
}