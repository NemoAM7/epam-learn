#include<iostream>
#include<typeinfo>

class Shape {
public:
	virtual ~Shape() {}
	virtual void draw() { std::cout << "Drawing Shape!" << std::endl; }
};

class Circle : public Shape {
public:
	void draw() { std::cout << "Drawing Circle!" << std::endl; }
	void circleSpecific() { std::cout << "Circle specific method!" << std::endl; }
};

class Rectangle : public Shape {
public:
	void draw() { std::cout << "Drawing Rectangle!" << std::endl; }
	void rectangleSpecific() { std::cout << "Rectangle specific method!" << std::endl; }
};
int main() {
	Shape* sh = new Circle();
	Circle* ci = static_cast<Circle*>(sh);

	ci->draw();
	ci->circleSpecific();

	sh = static_cast<Shape*>(ci);

	ci->draw();
	ci->circleSpecific();

	// Now, demonstrate bad static_cast (if type is wrong):
	Shape* s2 = new Rectangle();
	// Circle* c2 = static_cast<Circle*>(s2); // This is UNDEFINED BEHAVIOR if called!
	// Uncommenting the next two lines would cause errors or crashes if you wrongly cast:
	// c2->circleSpecific();

	Shape* sh2 = new Rectangle();
	// will safely cast, if not valid set to nullptr
	Rectangle* re1 = dynamic_cast<Rectangle*>(sh2);

	if (re1) {
		std::cout << "safe calls" << std::endl;
		re1->draw();
		re1->rectangleSpecific();
	}
	else {
		std::cout << "dynamic down cast to rectangle* failed" << std::endl;
	}

	Shape* sh3 = new Rectangle();
	// will safely cast, if not valid set to nullptr
	Circle* ci3 = dynamic_cast<Circle*>(sh3);

	if (ci3) {
		std::cout << "safe calls" << std::endl;
		ci3->draw();
		ci3->circleSpecific();
	}
	else {
		std::cout << "dynamic down cast to circle* failed" << std::endl;
	}

	delete sh;
	delete s2;
	delete sh2;
	delete sh3;

	/*
   static_cast blindly converts, and is UNDEFINED BEHAVIOR unless you know s points to the correct type.
   dynamic_cast checks types at runtime (for polymorphic hierarchies) and returns nullptr on failure.

   Use dynamic_cast for safe downcasting in polymorphic hierarchies when type safety matters.
   */

	return 0;
}

