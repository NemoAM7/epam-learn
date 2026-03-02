#include <typeinfo>
#include <iostream>

template<typename T>
void showType(T t) {
    std::cout << "Value: " << t << "\n";
    std::cout << "Deduced type: " << typeid(T).name() << "\n";
}

int main() {
    showType(10);    // int
    showType(3.14);  // double
    return 0;
}
