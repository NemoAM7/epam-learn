#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main() {
	auto i = 42;
	auto d = 3.14;
	auto s = string("abc");

	cout << "auto i = 42; type: " << typeid(i).name() << ", value: " << i << endl;
	cout << "auto d = 3.14; type: " << typeid(d).name() << ", value: " << d << endl;
	cout << "auto s = \"abc\"; type: " << typeid(s).name() << ", value: " << s << endl;

	int i2 = 42;
	double d2 = 3.14;
	string s2 = string("abc");

	cout << "int i2 = 42; type: " << typeid(i2).name() << ", value: " << i2 << endl;
	cout << "double d2 = 3.14; type: " << typeid(d2).name() << ", value: " << d2 << endl;
	cout << "string s2 = \"abc\"; type: " << typeid(s2).name() << ", value: " << s2 << endl;

	return 0;

}