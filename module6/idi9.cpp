#include "bigdata.hpp"
// No need for <vector>, <map>, <string>, or other heavy includes!
#include<iostream>

int main() {
    BigData bd;
    bd.process();
    std::cout << "BigData size: " << bd.getSize() << std::endl;
    return 0;
}