#include<iostream>
#include"widget.hpp"
using namespace std;

int main() {
    Widget w1("w1");
    w1.setName("PIMPL RuleOf5 Widget");
    w1.printName();

    std::cout << "--- copy constructor ---\n";
    Widget w2(w1);
    w2.printName();

    std::cout << "--- copy assignment ---\n";
    Widget w3("w3");
    w3 = w1;
    w3.printName();

    std::cout << "--- move constructor ---\n";
    Widget w4(std::move(w1));
    w4.printName();

    std::cout << "--- move assignment ---\n";
    Widget w5("w5");
    w5 = std::move(w2);
    w5.printName();
    return 0;
}
