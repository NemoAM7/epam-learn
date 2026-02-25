#include<iostream>
using namespace std;

int divide(int numerator, int denominator) {
	if (denominator == 0) {
		throw runtime_error("Zero Division Error : Cannot divide a number by zero");
	}

	return numerator / denominator;
}

int main() {
	int numerator, denominator;

	cout << "Enter two space seperated integers to divide: ";
	cin >> numerator >> denominator;

	try {
		cout << "floor(" << numerator << " / " << denominator << ") = " << divide(numerator, denominator) << endl;
	}
	catch (const runtime_error& e) {
		cout << "Error while dividing the number!" << endl;
		cout << "Traceback:" << endl;
		cout << e.what() << endl;

		return 1;
	}

	return 0;
}