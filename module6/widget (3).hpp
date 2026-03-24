#pragma once
#include <memory>
#include <string>
using namespace std;


class Widget {
public:
	Widget(const string& name);
	~Widget();

	Widget(const Widget& other);
	Widget(Widget&& other) noexcept;
	Widget& operator=(const Widget& other);
	Widget& operator=(Widget&& other) noexcept;
	void setName(const string& name);
	void printName() const;
private:
	struct WidgetImpl;
	unique_ptr<WidgetImpl> implPtr;
};