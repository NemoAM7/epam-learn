#include<iostream>
using namespace std;

// float infinity 
const float inf = 3.402823466e+38F;

// Function to perform addition
float add(float a, float b) {
	return a + b;
}

// Function to perform subtraction
float subtract(float a, float b) {
	return a - b;
}

// Function to perform multiplication
float multiply(float a, float b) {
	return a * b;
}

// Function to perform division
float divide(float a, float b) {
	if (b != 0) {
		return a / b;
	} else {
		return inf;
	}
}


int main() {
	bool mainLoop = true;
	float res;
	int choice;
	float num1, num2;

	while (mainLoop) {
		cout << "Enter two numbers: ";
		cin >> num1 >> num2;

		cout << "Choose an operation to perform:\n";
		cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide" << endl;
		cout << "Press any other key to exit." << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Result: " << add(num1, num2) << endl;
				break;
			case 2:
				cout << "Result: " << subtract(num1, num2) << endl;
				break;
			case 3:
				cout << "Result: " << multiply(num1, num2) << endl;
				break;
			case 4:
				res = divide(num1, num2);
				// divide by zero handling
				if (res != inf) {
					cout << "Result: " << res << endl;
				}
				else {
					cout << "Error: Division by zero is undefined" << endl;
				}
				break;

			default:
				cout << "Exiting..." << endl;
				break;
		}
	}
}