#include<iostream>
using namespace std;
struct Point {
  // public members
	int x;
	int y;
	
	// public setters
	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

  // public getters
	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};

class Rectangle {
  // private members
	int length;
	int width;

	public:
	// public setters
	void setLength(int length) {
		this->length = length;
	}

	void setWidth(int width) {
		this->width = width;
	}

  // public getters
	int getLength() {
		return length;
	}

	int getWidth() {
		return width;
	}
};

int main() {
  // Object creation
	Point point;
	Rectangle rect;

	// setter access 
	point.setX(1);
	point.setY(2);

	// public setter access
	rect.setLength(1);
	rect.setWidth(2);

  // Print update values
  cout << "First update" << endl;
	cout << "Point X: " << point.getX() << ", Y: " << point.getY() << endl;
	cout << "Rectangle L: " << rect.getLength() << ", W: " << rect.getWidth() << endl;

	// public variable access 
	point.x = 2;
	point.y = 3;
	
	// Cannot access private members of class!
  // rect.length = 10; Not possible
  // rect.width = 20; Not possible

  // Print updated values (only point gets changed!)
  cout << "Second Update" << endl;
	cout << "Point X: " << point.getX() << ", Y: " << point.getY() << endl;
	cout << "Rectangle L: " << rect.getLength() << ", W: " << rect.getWidth() << endl;
  
  return 0
}


