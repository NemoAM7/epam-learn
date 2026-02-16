#include<iostream>
#include<vector>

using namespace std;

class Shape {
public:
	virtual double area() const = 0;
};

class Rectangle : public Shape {
	double length;
	double width;
public:

	Rectangle(double length, double width) : length(length), width(width) {}

	double area() const override {
		return length * width;
	}
};


class Triangle : public Shape {
	double base;
	double height;
public:

	Triangle(double base, double height) : base(base), height(height) {}

	double area() const override {
		return 0.5 * base * height;
	}
};


class Circle : public Shape {
	double radius;
public:

	Circle(double radius) : radius(radius) {}

	double area() const override {
		return 3.14159 * radius * radius;
	}
};

int main() {
	vector<Shape*> shapes;

	shapes.push_back(new Circle(3));
	shapes.push_back(new Circle(2.4));
	shapes.push_back(new Rectangle(4, 2));
	shapes.push_back(new Rectangle(2.4, 3));
	shapes.push_back(new Triangle(3, 1.2));
	shapes.push_back(new Triangle(2.1, 2));


	for (Shape* shape : shapes) {
		cout << shape->area() << " unit^2" << endl;
	}

	for (Shape* shape : shapes) {
		delete shape;
	}
}