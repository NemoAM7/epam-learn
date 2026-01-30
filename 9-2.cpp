#include<iostream>
using namespace std;

// global const max size for array initalization
const int MAX_SIZE = 100000;

// Get array elements from user
void inputArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter value of Element " << i + 1 << " : ";
		cin >> arr[i];
	}
}

// Duplicate the array elements into another array in reverse order
void reverseArray(int arr[], int reversedArr[], int size) {
	for (int i = 0; i < size; i++) {
		reversedArr[size - i - 1] = arr[i];
	}
}

// Formatted printed array
void printArray(int arr[], int size) {
	cout << "arr( ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << ")\n";
}

int main() {
	
	// Declare variables for array with max size
	int arr[MAX_SIZE], reversedArr[MAX_SIZE];
	int size;


	// Get array size from user
	cout << "What should be the size of the array? : ";
	cin >> size;

	// Size validation
	if (size <= 0) {
		cout << "Size of array should be greater than 0!" << endl;
		return 1;
	}

	// Call functions for populating and reversing
	inputArray(arr, size);
	reverseArray(arr, reversedArr, size);

	// Formatted print
	cout << "Original : ";
	printArray(arr, size);
	cout << "Reversed : ";
	printArray(reversedArr, size);
	
	return 0;
}