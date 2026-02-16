#include<stdio.h>
#include<stdlib.h>

class DynamicArray {
public:
	int* data;
	int size;
	
	// Size constructor, default size in 5
	DynamicArray(int s = 5) : size(5) {

		// initialize array with zeros by given size
		data = new int[s];
		for (int i = 0; i < s; i++) {
			data[i] = 0;
		}
	}

	// Copy constructor for deep copy
	DynamicArray(const DynamicArray& other) : size(other.size) {
		printf("Copy consturctor called!\n");

		// initalize array with other's size and copy data
		data = new int[other.size];
		for (int i = 0; i < other.size; i++) {
			data[i] = other.data[i];
		}
	}

	// print values and their addresses
	void print() {
		printf("size : %d\n", size);
		for (int i = 0; i < size; i++) {
			printf("%d at %p, ", data[i], &data[i]);
		}
		printf("\n");
	}

	// destructor to free space
	~DynamicArray() {
		printf("Destructor called, freeing memory\n");
		
		delete[] data;
		data = NULL;
	}
};


int main() {
	// original array
	DynamicArray original(5);

	// copy array using copy constructor
	DynamicArray copy = original;

	// modify copied array to show that original is unaffected
	copy.data[0] = 10;

	// print both arrays to verify deep copy
	original.print();
	copy.print();
}