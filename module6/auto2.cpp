#include<iostream>
#include<typeinfo>

int main() {
    auto a = 5 + 2.5; // converted to double implictly 
    auto b = 3 * 1.5f; // converted to float explicitly

    std::cout << "auto a = 5 + 2.5; value: " << a << ", type: " << typeid(a).name() << std::endl; // double
    std::cout << "auto b = 3 * 1.5f; value: " << b << ", type: " << typeid(b).name() << std::endl; // float
