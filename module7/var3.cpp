#include<iostream>


void func(const int* x) {
	int* y = const_cast<int*>(x);
	*y = 20;
}

int main() {
	const int x = 10;
	// unsafe since casting a truly 
	int* y = const_cast<int*>(&x);

	*y = 20;
	// Undefined behaviour, may crash or cause segfault or seem to work
	std::cout << x << std::endl;


	int z = 10;
	func(&z);
	// valid since z was non-const
	std::cout << z << std::endl;

	/*
   SUMMARY:
   - It is ONLY safe to write via const_cast when the original variable wasn't really declared as const.
   - Writing to a truly const object (e.g., global/static const, string/const literal) is undefined behavior (often segfaults).
   - Use const_cast only for legacy APIs, never to break logical constness!
   */

	return 0;
}