#include"widget.hpp"
#include<iostream>

using namespace std;

struct Widget::WidgetImpl {
	string name;
	char* buffer;
	WidgetImpl(const string& name) : name(name), buffer(new char[100]) {
		cout << "Widget initialized: " << name << endl;
		strcpy(buffer, name.c_str());
		buffer[99] = '\0';
		cout << "buffer initalized at " << static_cast<void*>(buffer) << endl;
	}

	~WidgetImpl() {
		cout << "deleting buffer at " << static_cast<void*>(buffer) << endl;
		delete[] buffer;
	}
};

Widget::Widget(const string& name) : implPtr(make_unique<WidgetImpl>(name)) {}

Widget::~Widget() = default;

void Widget::setName(const string& name) {
	implPtr->name = name;
	strcpy(implPtr->buffer, name.c_str());
	implPtr->buffer[99] = '\0';
}

void Widget::printName() const {
	cout << "Name is " << implPtr->name << ", buffer: " << implPtr->buffer << endl;
}

