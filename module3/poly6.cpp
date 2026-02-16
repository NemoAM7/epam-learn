#include<iostream>
using namespace std;

class Printer{
public:
	virtual void print(const std::string& msg = "Base Printer") {
		cout << msg << endl;
	}
};

class ColorPrinter : public Printer {
public:
	virtual void print(const std::string& msg = "Color Printer") override {
		cout << msg << endl;
	}
};

int main() {
	ColorPrinter cp;
	cp.print();

	Printer* p1 = &cp;
	p1->print();

}