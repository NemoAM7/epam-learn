#include<iostream>
#include<vector>

using namespace std;

// Abstract base class for shapes
class Shape {
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual ~Shape() {
		cout << "Shake destructed!" << endl;
	}
};	

// Derived class for Circle
class Circle : public Shape {
private:
	double radius;
public:
	Circle(double radius) : radius(radius) {}

	double area() const override {
		return 3.14159 * radius * radius;
	}

	double perimeter() const override {
		return 2 * 3.14159 * radius;
	}

	~Circle() {
		cout << "Shake destructed!" << endl;
	}
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
	double length;
	double width;
public:
	Rectangle(double length, double width) : length(length), width(width) {}

	double area() const override {
		return length * width;
	}

	double perimeter() const override {
		return 2 * (length + width);
	}

	~Rectangle() {
		cout << "Shake destructed!" << endl;
	}
};

// Derived class for Triangle
class Triangle : public Shape {
private:
	double sideA;
	double sideB;
	double sideC;
public:
	Triangle(double sideA, double sideB, double sideC) : sideA(sideA), sideB(sideB), sideC(sideC) {}

	double area() const override {
		double s = (sideA + sideB + sideC) / 2;
		return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
	}

	double perimeter() const override {
		return sideA + sideB + sideC;
	}

	~Triangle() {
		cout << "Shake destructed!" << endl;
	}
};

int main() {
	// Create a vector of shape pointers
	vector<Shape*> shapes;

	// Add different shapes to the vector
	shapes.push_back(new Circle(2));
	shapes.push_back(new Rectangle(3, 4));
	shapes.push_back(new Triangle(3, 4, 5));
	shapes.push_back(new Rectangle(5, 6));
	shapes.push_back(new Circle(3));
	shapes.push_back(new Triangle(6, 8, 10));

	// Display area and perimeter of each shape
	for (Shape* shape : shapes) {
		cout << "Area of shape: " << shape->area() << endl;
		cout << "Perimeter of shape: " << shape->perimeter() << endl;
		delete shape;
	}
}