#include"widget.hpp"
#include<iostream>

using namespace std;

struct Widget::WidgetImpl {
	string name;

	WidgetImpl(const string& name) : name(name) {
		cout << "Widget initialized: " << name << endl;
	}
};

Widget::Widget(const string& name) : implPtr(make_unique<WidgetImpl>(name)) {}

Widget::~Widget() = default;

void Widget::setName(const string& name) {
	implPtr->name = name;
}

void Widget::printName() const {
	cout << "Name is " << implPtr->name << endl;
}

