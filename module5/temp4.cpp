#include <iostream>
#include <string>
#include <utility>

template<typename... Args>
void process(Args&&... args) {
    ((std::cout << std::forward<Args>(args) << " "), ...);
    std::cout << std::endl;
}

template<typename... Args>
void forwardAll(Args&&... args) {
    process(std::forward<Args>(args)...);
}

int main() {
    int x = 5;

    // Test 1: Mixed lvalues and rvalues
    forwardAll(x, 2.5, std::string("hello"), 100);

    // Test 2: Rvalues and expressions
    forwardAll(std::string("temp"), x + 1);

    // Test 3: Const lvalue
    const std::string greeting = "Namaste";
    forwardAll(greeting);

    return 0;
}