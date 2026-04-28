#include<iostream>
#include<thread>

std::atomic<int> value{ 10 };

int main() {
	std::cout << "Value: " << value << std::endl;
	int prev = value.fetch_add(5);
	std::cout << "Value after adding 5: " << prev << "->" << value << std::endl;
	prev = value.fetch_sub(3);
	std::cout << "Value after subtracting 3: " << prev << "->" << value << std::endl;
	prev = value.exchange(42);
	std::cout << "Value after exchanging 42: " << prev << "->" << value << std::endl;

	return 0;
}