#include<iostream>

using namespace std;


// allocates memory for an integer, assigns it a value, and returns a pointer to it
int* allocate() {
	int* p = new int;
	*p = 10;
	return p;
}

int main() {

	// get the pointer to the allocated memory
	int* p = allocate();

	// print the value stored at the allocated memory
	cout << *p << endl;

	// delete the allocated memory
	delete p;
	
	// Undefined behaviour, pointer deallocated
	cout << "Attempt to access after deallocation : " << *p << endl;
	
	// After deallocation the pointer still holds the address of deallocated memory
	// this is called a dangling pointer, accessing it will lead to undefined behaviour
	// set the pointer to nullptr after deallocation to avoid dangling poinater
	p = nullptr;

	//  Read access violation, pointer is nullptr
	cout << *p << endl;

	return 0;
}