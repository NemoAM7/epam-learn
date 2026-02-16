#include<stdio.h>
#include<stdlib.h>

class DynamicArray {
public:
	int* data;
	int size;
	
	// Size constructor, default size in 5
	DynamicArray(int s = 5) : size(s) {
		printf("created at %p with %d elements and %d bytes\n", this, s, s*sizeof(int));
		// initialize array with zeros by given size
		data = new int[s];
		for (int i = 0; i < s; i++) {
			data[i] = 0;
		}
	}

	// Copy constructor for deep copy
	DynamicArray(const DynamicArray& other) : size(other.size) {
		printf("Copy constructor called!, copying elements from %p to %p with %d elements and %d bytes\n", other, this, other.size, other.size*sizeof(int));

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
		printf("Destructor called, freeing memory at %p with %d elements and %d bytes\n", this, size, size*sizeof(int));
		
		delete[] data;
		data = NULL;
	}
};


void demoDestructor() {
	printf("array2, array3, array4 will be created!\n");
	DynamicArray array2(20);
	DynamicArray array3 = array2;
	DynamicArray array4(54);
	printf("array2, array3, array4 will be destroyed!\n");
} // end of scope for array2 and array3

int main() {
	printf("array1 will be created!\n");
	DynamicArray array1(30); // array1 created, constructor will be called

	demoDestructor(); // array2 and array3 created inside function and destructed after function ends
	printf("array1 will be destroyed!\n");
} // end of scope for array1 after main terminates