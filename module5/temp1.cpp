#include<iostream>
using namespace std;

void printAll() {}

template<typename T, typename... Args>
void printAll(T first, Args... args) {
	cout << first << " ";
	printAll(args...);
}


int main() {
	printAll("abcd", 1234, 24324.35, true, NULL, 'c');
}