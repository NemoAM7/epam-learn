#include<iostream>
using namespace std;

class Rectangle;
class Circle;

class Rectangle {
	double length;
	double width;
public:
	Rectangle(double length, double width) : length(length), width(width) {}
	friend double compareArea(const Rectangle&, const Circle&);
};

class Circle {
	double radius;
public:
	Circle(double radius) : radius(radius){}
	friend double compareArea(const Rectangle&, const Circle&);
};

double compareArea(const Rectangle& rectangle, const Circle& circle) {
	int rect_area = rectangle.length * rectangle.width;
	int circ_area = circle.radius * circle.radius * 3.14159;
	if (rect_area == circ_area) {
		cout << "Both areas are equal!" << endl;
		return rect_area;
	}
	else if (rect_area < circ_area) {
		cout << "Circle area is bigger" << endl;
		return circ_area;
	}
	else {
		cout << "Rectangle area is bigger" << endl;
		return rect_area;
	}
}

int main() {
	Rectangle r1(2.3, 3.2);
	Circle c1(2.1);
	cout << compareArea(r1, c1) << endl;
}