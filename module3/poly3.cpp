#include<iostream>
#include<vector>
using namespace std;

class Fraction {
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator) : numerator(numerator) {
		if (denominator < 0) {
			cout << "Denominator cant be zero, set to 1!" << endl;
			denominator = 1;
		}

		this->denominator = denominator;
	}

	bool operator==(Fraction other) {
		return numerator * other.denominator == other.numerator * denominator;
	}
	
	bool operator<(Fraction other) {
		return numerator * other.denominator < other.numerator * denominator;
	}

	friend ostream& operator<<(ostream& os, Fraction other) {
		os << other.numerator << "/" << other.denominator;
		return os;
	}
};

int main() {
	vector<Fraction> fractions;
	fractions.push_back(Fraction(1, 2));
	fractions.push_back(Fraction(2, 4));
	fractions.push_back(Fraction(1, 3));

	for (int i = 0; i < fractions.size(); i++) {
		for (int j = i+1; j < fractions.size(); j++) {
			Fraction f1 = fractions[i], f2 = fractions[j];
			cout << f1 << " < " << f2 << " -> " << (f1 < f2) << endl;
			cout << f1 << " == " << f2 << " -> " << (f1 == f2) << endl;
		}
	}
}