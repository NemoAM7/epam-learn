#include"widget.hpp"
#include<iostream>

using namespace std;

struct Widget::WidgetImpl {
	string name;
	char* buffer;
	WidgetImpl(const string& name) : name(name), buffer(new char[100]) {
		cout << "(impl) Widget initialized: " << name << endl;
		strcpy(buffer, name.c_str());
		buffer[99] = '\0';
		cout << "(impl) buffer initalized at " << static_cast<void*>(buffer) << endl;
	}

	~WidgetImpl() {
		cout << "(impl) deleting buffer at " << static_cast<void*>(buffer) << endl;
		delete[] buffer;
	}

	WidgetImpl(const WidgetImpl& other) : name(other.name), buffer(new char[100]) {
		cout << "(impl) copy ctor, buffer at " << static_cast<void*>(buffer) << endl;
		strcpy(buffer, other.buffer);
	}

	WidgetImpl& operator=(const WidgetImpl& other) {
		if (this != &other) {
			name = other.name;
			strcpy(buffer, other.buffer);
		}
		return *this;
	}
};

Widget::Widget(const string& name) : implPtr(make_unique<WidgetImpl>(name)) {}

Widget::~Widget() = default;

Widget::Widget(const Widget& other) : implPtr(make_unique<WidgetImpl>(*other.implPtr)){}

Widget& Widget::operator=(const Widget& other) {
	if (this != &other) {
		*implPtr = *other.implPtr;
	}
	return *this;
}

Widget::Widget(Widget&& other) noexcept : implPtr(move(other.implPtr)) {}

Widget& Widget::operator=(Widget&& other) noexcept {
	if (this != &other) {
		implPtr = move(other.implPtr);
	}
	return *this;
}

void Widget::setName(const string& name) {
	implPtr->name = name;
	strcpy(implPtr->buffer, name.c_str());
	implPtr->buffer[99] = '\0';
}

void Widget::printName() const {
	cout << "Name is " << implPtr->name << ", buffer: " << implPtr->buffer << endl;
}

