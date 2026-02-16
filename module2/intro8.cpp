#include<iostream>

using namespace std;


class Box {
	int length, width, height;

public:
	// Sets the dimensions of the box
	void setDimensions(int length, int width, int height) {
		this->length = length;
		this->width = width;
		this->height = height;
	}
	
	// Compares the volume of the current box with another box and returns the box with the larger volume
	Box compareVolume(const Box& other) {
		if (other.getVolume() > this->getVolume()) {
			return other;
		}
		return *this;
	}

	// Calculates and returns the volume of the box
	int getVolume() const {
		return length * width * height;
	}
	
	// Prints the dimensions and volume of the box
	void print() const{
		cout << "Length: " << length << ", Width: " << width << ", Height: " << height << ", Volume: " << getVolume() << endl;
	}
};

int main() {
	// Create two Box objects and set their dimensions
	Box box1, box2;
	box1.setDimensions(1, 2, 3);
	box2.setDimensions(3, 4, 5);
	 
	// Print the dimensions and volume of both boxes
	cout << "Box 1\n";
	box1.print();
	cout << "Box 2\n";
	box2.print();

	// Compare the two boxes and print the larger one
	cout << "Larger box out of two\n";
	Box largerBox = box1.compareVolume(box2);

	largerBox.print();
}