#include<iostream>

int main() {
	int a = 10;
	double b = 3.7;

	double ad1 = (double)a;
	int bi1 = (int)b;

	double ad2 = static_cast<double>(a);
	int bi2 = static_cast<int>(b);

	std::cout << "double a (c-style): " << ad1 << std::endl;
	std::cout << "double a (static_cast): " << ad2 << std::endl;
	std::cout << "int b (c-style): " << bi1 << std::endl;
	std::cout << "int b (static_cast): " << bi2 << std::endl;

	/*
	static_cast is preferred over C-style casts because:
	  - It's more explicit and searchable in code.
	  - It disallows dangerous reinterpretation or narrowing conversions unless explicit.
	  - C-style cast can perform several kinds of conversions (static, const, reinterpret) and is therefore riskier.
	  - static_cast is easier to find in code review and refactoring.
	*/

	return 0;
}