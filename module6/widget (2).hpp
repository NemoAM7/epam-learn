#pragma once
#include <memory>
#include <string>
using namespace std;


class Widget {
public:
	Widget(const string& name);
	~Widget();
	void setName(const string& name);
	void printName() const;
private:
	struct WidgetImpl;
	unique_ptr<WidgetImpl> implPtr;
};