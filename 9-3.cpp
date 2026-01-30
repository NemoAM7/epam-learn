#include<iostream>
#include<stdlib.h>
using namespace std;

const int MAX_SIZE = 10000;

// Bubble sort 
void bubbleSort(int arr[], int size) {
	int temp;
	int changes;
	for (int i = size; i > 1; i--) {
		changes = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				changes++;
			} 
		}
		if (changes == 0) break;
	}
}

// Selection sort
void selectionSort(int arr[], int size) {
	int temp;
	int min_idx;
	for (int i = 0; i < size; i++) {
		min_idx = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}

// custom compare function for qSort
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

// Wrapper to call qsort on an integer array
void qsortWrapper(int arr[], int size) {
	qsort(arr, size, 4, compare);
}

// Formatted printed array
void printArray(int arr[], int size) {
	cout << "arr( ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << ")\n";
}

// Get array elements from user
void inputArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter value of Element " << i + 1 << " : ";
		cin >> arr[i];
	}
}

int main() {
	int arr[MAX_SIZE];
	int size;
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


	// Display Menu
	int choice;
	cout << "Choose the sorting algorithm.\n[1]Bubble\n[2]Selection\n[3]Qsort\nPress any other key to exit!\n";
	cin >> choice;
	
	cout << "Original : ";
	printArray(arr, size);

	// Perform sorting based on choice
	switch (choice) {
	case 1:
		cout << "Performing Bubbble sort!\n";
		bubbleSort(arr, size);
		break;
	case 2:
		cout << "Performing Selection sort!\n";
		selectionSort(arr, size);
		break;
	case 3:
		cout << "Performing Qsort!\n";
		qsortWrapper(arr, size);
		break;
	default:
		cout << "Thanks for using! Exiting...\n";
		return 0;
	}
	cout << "Sorted : ";
	printArray(arr, size);

	return 0;
}