#include<iostream>
#include<memory>
using namespace std;

class Widget {
public:
	Widget() { cout << "Widget is created!" << endl; }
	~Widget() { cout << "Widget is destroyed!" << endl; }
	void print() const { cout << "This is a widget!" << endl; }
};

unique_ptr<Widget> func() {
	auto ptr = make_unique<Widget>();
	ptr->print();
	return ptr;
}

int main() {
	{
		auto widgetPtr = func();
		widgetPtr->print();
	}// out of scope destructs

	{
		Widget* w = new	Widget();
		w->print();
		delete w;
	}// widget persists if raw pointers not deleted

	return 0;
}