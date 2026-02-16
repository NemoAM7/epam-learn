#include<iostream>
using namespace std;
class Complex {
public:
	double real;
	double img;

	Complex(double real, double img): real(real), img(img){}

	Complex operator+(Complex other) {
		return Complex(other.real + real, other.img + img);
	}

	friend ostream& operator<<(ostream& os, const Complex& other);

};

ostream& operator<<(ostream& os, const Complex& other) {
	if (other.img < 0) {
		os << "( " << other.real << " - " << -other.img << "i )";
	}
	else {
		os << "( " << other.real << " + " << other.img << "i )";
	}
	
	return os;
}

int main() {
	Complex a(2.2, -3);
	Complex b(-3, 3.8);

	Complex c = a + b;

	cout << a << " + " << b << " = " << c << endl;
}