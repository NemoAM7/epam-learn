#include<iostream>
using namespace std;

int main() {

	// Variable declaration for input and output
	int choice, num1, num2, result;

	// Operator array for display purposes
	char operators[4] = {'+', '-', '*', '/'};
	
	// Display menu of options
	cout << "Calculator Menu:\n";
	cout << "Choose an operation:\n";
	cout << "[1] Addition \n";
	cout << "[2] Subtraction \n";
	cout << "[3] Multiplication \n";
	cout << "[4] Division \n";

	// Get user choice and operands
	cin >> choice;
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	// Switch case to handle different operations
	switch (choice)
	{
	case 1: // Addition
		result = num1 + num2;
		break;
	case 2: // Subtraction
		result = num1 - num2;
		break;
	case 3: // Multiplication
		result = num1 * num2;
		break;
	case 4: // Division
		result = num1 / num2;
		break;
	default: // Invalid choice
		cout << "Invalid Choice!\n";
		return 1;
	}
	
	// Display the result
	cout << "Result: " << num1 << " " << operators[choice - 1] << " " << num2 << " = " << result << "\n";

	return 0;
}