#include<iostream>
using namespace std;

template<typename T = int>
class Number {
	T value;
public:
	Number(T v) : value(v) {}
	void print() const {
		cout << value << endl;
		cout << "type: " << typeid(T).name() << endl;
	}
};

int main() {
	Number<> n1(100);
	Number<double> n2(3.14);

	n1.print();
	n2.print();
}