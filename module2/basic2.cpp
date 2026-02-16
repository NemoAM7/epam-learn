#include<iostream>
using namespace std;

int main() {
	// Dynamic memory allocation using new operator and malloc function
	int* arr = new int[5];
	int* brr = (int*)malloc(5 * sizeof(int));

	// Initializing the arrays
	for (int i = 0; i < 5; i++) {
		arr[i] = i * i + 2;
		brr[i] = i * i + 2;
	}

	// Displaying the array made using new operator and malloc function
	cout << "Array created using new operator: ";
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Array created using malloc function: ";
	for (int i = 0; i < 5; i++) {
		cout << brr[i] << " ";
	}
	cout << endl;

	// Deallocating the memory
	delete[] arr;
	free(brr);

	// Setting pointers to NULL after deallocation
	arr = NULL;
	brr = NULL;
}