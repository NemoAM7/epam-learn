#include<iostream>
#include"widget.hpp"
using namespace std;

int main() {
	Widget w("abcd");
	w.printName();
	w.setName("bcda");
	w.printName();
}