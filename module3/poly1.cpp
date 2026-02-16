#include<iostream>
using namespace std;
class Calculator {
public:
	int add(int a, int b) {
		return a + b;
	}

	double add(double a, double b) {
		return a + b;
	}

	string add(string a, string b) {
		return a + b;
	}
};

int main() {
	Calculator calc;

	int a_int = 2, b_int = 3;
	double a_double = 2.5, b_double = 3.5;	
	string a_string = "2.5", b_string = "3.5";

	cout << "Integer addition: " << a_int << " + " << b_int << " = " << calc.add(a_int, b_int) << endl;
	cout << "Double addition: " << a_double << " + " << b_double << " = " << calc.add(a_double, b_double) << endl;
	cout << "String addition: " << a_string << " + " << b_string << " = " << calc.add(a_string, b_string) << endl;
}