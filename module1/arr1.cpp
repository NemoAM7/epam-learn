#include<iostream>
using namespace std;

// Gets the array element from the user by taking the array reference and size
void inputArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter the value for the " << i+1 << "th element: ";
		cin >> arr[i];
	}
}

// Calculates the sum of array given its size
int sumArray(int arr[], int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += arr[i];
	}
	return total;
}

// Calculates the average value given the sum and count of observations
float calculateAverage(int sum, int size) {
	return (float)sum / size;
}

// Display function, displays the array elements, size and the average in a user friendly format.

// example output "Array( [ 1, 2, 3, ], sum = 6, average = 2, )"
void printArray(int arr[], int size) {
	int sum = sumArray(arr, size);
	int avg = calculateAverage(sum, size);

	cout << "Array( ";
	cout << "[ ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << "], ";

	cout << "sum = " << sum << ", ";
	cout << "average = " << avg << ", ";

	cout << ")\n";
}

int main() {

	// Max size of array
	const int MAX_SIZE = 100;

	// Declarations
	int arr[MAX_SIZE];
	int size;

	cout << "What should the size or array be? : ";
	cin >> size;

	if (size >= MAX_SIZE) {
		cout << "Size is too large, please make sure its less than 100000!" << endl;
		return 1;
	}

	if (size <= 0) {
		cout << "Size is too small, please make sure its more than 0!" << endl;
		return 1;
	}

	// Populating the array
	inputArray(arr, size);

	//Displaying the array
	printArray(arr, size);
}