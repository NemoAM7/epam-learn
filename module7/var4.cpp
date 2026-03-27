#include <iostream>
#include <iomanip>

int main() {
    int value = 0x12345678;
    std::cout << "int value = 0x" << std::hex << value << std::dec << std::endl;

    // Print raw bytes (shows endianness)
    std::cout << "Bytes of value: ";
    char* pchar = reinterpret_cast<char*>(&value);
    for (size_t i = 0; i < sizeof(int); ++i) {
        std::cout << "0x" << std::hex << (0xFF & pchar[i]) << " ";
    }
    std::cout << std::dec << std::endl;

    // Unsafe pointer cast between unrelated types (DO NOT DO THIS IN PRACTICE)
    int a = 42;
    double* pd = reinterpret_cast<double*>(&a);
    std::cout << "Trying to read int memory as double: *pd = " << *pd << std::endl;
    // Writing through this is even worse: *pd = 1.23; // UB

    /*
    Discussion:
    - reinterpret_cast simply reinterprets the bit pattern. No checking, no type safety.
    - Reading or writing memory this way is undefined behavior unless you know exactly what you're doing.
    - Platform/architecture assumptions (like endianness, size, alignment) can break code that uses reinterpret_cast carelessly.
    - Use reinterpret_cast only for low-level system programming, hardware interfaces, unions, and serialization libraries.
    - Prefer safer casts (static_cast, const_cast, dynamic_cast) for normal C++ code.
    */

    return 0;
}