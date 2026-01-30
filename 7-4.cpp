#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

vector<long long> g_fact = { 1 }; // global factorial cache

// Memoized Factorial function : (x) -> x! 
long long factorial(int x) {
	if (g_fact.size() <= x) {
		g_fact.push_back(x * factorial(x - 1));
	}
	return g_fact[x];
}

// Calculates the n-th term of the Taylor series for e^x : (x,n) -> x^n / n!
float term(int x, int n) {
	float power = 1;
	for (int i = 0; i < n; i++) {
		power *= x;
	}
	return power / factorial(n);
}

// Calculates e^x using Taylor series expansion up to 'terms' terms (x, terms) -> e^x (terms approxmiation)
float expTaylor(int x, int terms) {
	float res = 0;
	for (int t = 1; t <= terms; t++) {
		res = res + term(x, t - 1);
	}
	return res;
}

int main() {

	// User input for x and number of terms
	int x, terms;

	// Variables to hold calculated value, actual value and absolute error
	float calculated_value, actual_value, absolute_error;

	cout << "e^x Calculator\n";
	cout << "Enter the value of x: ";
	cin >> x;
	cout << "Enter the number of terms for approximation: ";
	cin >> terms;

	if (terms > 0 && x > 0){
		calculated_value = expTaylor(x, terms);                       // compute the approximation
		actual_value = exp(x);                                        // compute the actual value using standard library
		absolute_error = abs(actual_value - expTaylor(x, terms));     // compare the two values

		cout << "e^" << x << " approximated using " << terms << " terms is: " << calculated_value << endl;
		cout << "Actual e^" << x << " value is: " << actual_value << endl;
		cout << "Absolute error is: " << absolute_error << endl;

		cout << "Absolute error decreases as the number of terms increases." << endl;

		// Show error for terms from 1 to 10
		for (terms = 1; terms <= 10; terms++) {
			calculated_value = expTaylor(x, terms);
			absolute_error = abs(actual_value - calculated_value);
			cout << "Terms: " << terms << ", Absolute Error: " << absolute_error << endl;
		}
	} 
	else {
		cout << "Number of terms & value of 'x' must be positive." << endl;
		return 1;
	}

	return 0;
}