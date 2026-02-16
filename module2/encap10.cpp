#include<iostream>;
using namespace std;

// Abstract base class
class Shape {
public:
	virtual void draw() const = 0;

	virtual double area() const = 0;

	virtual double perimeter() const = 0;
};


// Derived class for Circle
class Circle : public Shape {
	double radius;
public:
	Circle(double r) : radius(r) {}

	void draw() const override {
		cout << "Drawing a square." << endl;
	}

	double area() const override {
		return 3.14159 * radius * radius;
	}

	double perimeter() const override {
		return 2 * 3.14159 * radius;
	}

	double getRadius() const {
		return radius;
	}
};

// Derived class for Square
class Square : public Shape {
	double length;
public:
	Square(double l) : length(l) {}

	void draw() const override {
		cout << "Drawing a square." << endl;
	}

	double area() const override {
		return length * length;
	}

	double perimeter() const override {
		return 4 * length;
	}

	double getLength() const {
		return length;
	}
};

// Derived class for Rectangle
class Rectangle : public Shape {
	double width;
	double height;
public:
	Rectangle(double w, double h) : width(w), height(h) {}

	void draw() const override {
		cout << "Drawing a rectangle." << endl;
	}
	double area() const override {
		return width * height;
	}
	double perimeter() const override {
		return 2 * (width + height);
	}

	double getWidth() const {
		return width;
	}

	double getHeight() const {
		return height;
	}
};

int main() {
	Circle circle(5.0);
	Square square(4.0);
	Rectangle rectangle(3.0, 6.0);
	circle.draw();
	cout << "Circle area: " << circle.area() << endl;
	cout << "Circle perimeter: " << circle.perimeter() << endl;
	cout << "Circle radius: " << circle.getRadius() << endl;
	square.draw();
	cout << "Square area: " << square.area() << endl;
	cout << "Square perimeter: " << square.perimeter() << endl;
	cout << "Square length: " << square.getLength() << endl;
	rectangle.draw();
	cout << "Rectangle area: " << rectangle.area() << endl;
	cout << "Rectangle perimeter: " << rectangle.perimeter() << endl;
	cout << "Rectangle width: " << rectangle.getWidth() << endl;
	cout << "Rectangle height: " << rectangle.getHeight() << endl;
	return 0;

}