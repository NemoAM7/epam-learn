#include<iostream>

class Animal {
public:
	virtual ~Animal() {}
	virtual void sound() const { std::cout << "mmmmm" << std::endl; }
};

class Dog : public Animal {
public:
	~Dog() {}
	void dogSpecific() const { std::cout << "Dog specific method" << std::endl; }
	void sound() const { std::cout << "woof" << std::endl; }
};

class Cat : public Animal {
public:
	~Cat() {}
	void catSpecific() const { std::cout << "Cat specific method" << std::endl; }
	void sound() const { std::cout << "meow" << std::endl; }
};

int main() {
	Animal* a = new Animal(), * b = new Dog(), * c = new Cat();

	std::cout << typeid(*a).name() << " " << typeid(*b).name() << " " << typeid(*c).name() << std::endl;

	Dog* bd = dynamic_cast<Dog*>(b);
	Cat* cc = dynamic_cast<Cat*>(c);

	if (bd) bd->dogSpecific();
	if (cc) cc->catSpecific();

	delete a;
	delete b;
	delete c;

	/*
   - Use typeid to simply query/display an object's dynamic type at runtime.
   - Use dynamic_cast to safely downcast and access derived-class-specific methods or fields.
   - If RTTI is disabled (e.g. with -fno-rtti), typeid and dynamic_cast won't work for polymorphic types and may result in compile or runtime errors.
   - dynamic_cast returns nullptr (for pointers) when the cast fails.
   - Never use static_cast for polymorphic downcasts unless you're 100% sure of the type.
   */

	return 0;
}
