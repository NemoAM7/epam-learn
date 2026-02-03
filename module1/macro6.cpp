#ifndef MYHEADER_H   // Check if MYHEADER_H is not defined
#define MYHEADER_H   // Define MYHEADER_H

// Header file content
#define PI 3.14159
void printMessage();

#endif // End inclusion guard


// file1.cpp
#include "myheader.h"
#include <iostream>
void printMessage() {
    std::cout << "This is a message printed from file1.c\n";
}

int main() {
    printMessage();
}

// file2.cpp
#include "myheader.h"
#include <iostream>
void calculateArea(int radius) {
    std::cout << "area of circle: " << PI*radius*radius << "\n";
}

int main() {
    calculateArea(10);
}