#include<iostream>
using namespace std;

void printAll() {
	cout << endl;
}

template<typename... Args>
void printAll(int a, Args... args) {
	cout << a << " ";
	printAll(args...);
}

int main() {
	printAll(1, 2, 3, 4);
	printAll(1);
	printAll();
}