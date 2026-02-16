#include<iostream>

#define SQUARE(x) (x)*(x)


using namespace std;

class Math {
public:
	static inline int square(int x) {
		return x * x;
	}
};

int main() {
	cout << "Square with Math class\n";
	cout << "3^2 = " << Math::square(3) << endl;
	cout << "(1+2)^2 = " << Math::square(1 + 2) << endl;	
	cout << "(2.5)^2 = " << Math::square(2.5) << endl; // Integer version of square will be called, which may lead to loss of precision
	
	cout << "Square with macro\n";
	cout << "3^2 = " << SQUARE(3) << endl;
	cout << "(1+2)^2 = " << SQUARE(1 + 2) << endl; // This will work as expected due to parantheses in macro definition
	cout << "(2.5)^2 = " << SQUARE(2.5) << endl; // less type safety and may lead to unexpected results due to macro expansion
}