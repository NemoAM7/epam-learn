#include<iostream>
#include<thread>
#include<vector>

int counter = 0;

void increment() {
	for (int i = 0; i < 10000; i++) {
		counter++;
		// threads incrementing a shared resource
		// less atomicity so some increments might overlap
	}
}

int main() {
	std::vector<std::thread> threads;
	for (int i = 0; i < 4; i++) {
		threads.emplace_back(std::thread(increment));
	}
	for (std::thread& t : threads) {
		t.join();
	}

	std::cout << "Counter: " << counter << std::endl;
}