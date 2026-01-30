#include<iostream>
#include<numbers>

using namespace std;

// Function to compute factorial
long long factorial(int x) {
	long long  prod = 1;

	for (int i = 2; i <= x; i++) {
		prod *= i;
	}

	return prod;
}

// Function to compute Nth term for X radians in the sin taylor series;
float term(float x, int n) {

	int parity = -1;
	if (n % 2 == 1) parity = 1;

	double product = 1;

	for (int i = 0; i < 2 * n - 1; i++) {
		product *= x;
	}
	//cout << parity << " " << x << " " << factorial(2 * n - 1) << endl;
	return parity * product / factorial(2 * n - 1);
}

// Function to approximate sin(X) with 'terms' terms by taking sum of all terms
float sinTaylor(float x, int terms) {
	
	float res = 0;

	for (int i = 1; i <= terms; i++) {
		res += term(x, i);
	}

	return res;
}


// Function to run an execution for x_deg and temrs
void run(float x_deg, int terms) {
	float x_rad;

	x_rad = x_deg * std::numbers::pi / 180;

	float calculatedValue, actualValue = sin(x_rad);

	cout << "====================" << endl;
	cout << "Angle in degrees: " << x_deg << endl;
	cout << "Angle in radians: " << x_rad << endl;
	cout << "Actual Value of sine function: " << actualValue << endl;
	for (int i = 1; i <= terms; i++) {
		calculatedValue = sinTaylor(x_rad, i);
		cout << "Number of terms used for approximation: " << terms << endl;
		cout << "Approximated Value of sine function "
			<< calculatedValue << endl;
		cout << "Absolute Error: " << abs(calculatedValue - actualValue) << endl;
	}
	
}

int main() {
	float x_deg;
	int terms;

	cout << "Enter the angle of sine function (degrees): ";
	cin >> x_deg;
	cout << "Enter the number of terms for approximation: ";
	cin >> terms;
	if (terms <= 0) {
		cout << "Number of terms cannot be negative.";
		return 1;
	}
	
	run(x_deg, terms);

	// test runs
	run(0, terms);
	run(90, terms);
	run(180, terms);
	run(360, terms);

	return 0;
	
}