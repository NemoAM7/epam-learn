#include<iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;

// Perform linear search : O(size)
int linearSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) return i;
	}
	return -1;
}

// Perform binary search : O(log size)
int binarySearch(int arr[], int size, int key) {
	int low = 0;
	int high = size - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == key) return mid;
		else if (arr[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

// Formatted printed array
void printArray(int arr[], int size) {
	cout << "arr( ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << " )\n";
}

// Get array elements from user
void inputArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter value of Element " << i + 1 << " : ";
		cin >> arr[i];
	}
}

// Check if array is sorted
bool isSorted(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		if (arr[i] < arr[i - 1]) return false;
	}
	return true;
}

// Displays the outcome of search
void printResult(int index, int key) {
	if (index == -1) {
		cout << "Value " << key << " not present in the array!" << endl;
	}
	else {
		cout << "Value " << key << " found at index " << index << "!" << endl;
	}
}

int main() {
	int arr[MAX_SIZE];
	int size, value, index;
	// Get array size from user
	cout << "What should be the size of the array? : ";
	cin >> size;

	// Size validation
	if (size <= 0) {
		cout << "Size of array should be greater than 0!" << endl;
		return 1;
	}

	// Call functions for populating
	inputArray(arr, size);

	cout << "values : ";
	printArray(arr, size);

	// Display Menu
	int choice;
	cout << "Choose the search algorithm.\n[1]Linear\n[2]Binary\nPress any other key to exit!\n";
	cin >> choice;

	// Get the key from the user
	cout << "What is the value youre looking for? : ";
	cin >> value;

	// Perform searching based on choice
	switch (choice) {
	case 1:
		cout << "Performing Linear search\n";
		index = linearSearch(arr, size, value);
		printResult(index, value);
		break;
	case 2:
		cout << "Performing Binary search\n";

		if (!isSorted(arr, size)) {
			cout << "Array not sorted, sorting the array!" << endl;
			sort(arr, arr + size);
			cout << "values : ";
			printArray(arr, size);
		}
		
		index = binarySearch(arr, size, value);

		printResult(index, value);
		break;
	default:
		cout << "Thanks for using! Exiting...\n";
		return 0;
	}

	return 0;
}