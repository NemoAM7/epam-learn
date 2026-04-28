#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

int counter = 0;

std::mutex key;

void increment() {
	for (int i = 0; i < 10000; i++) {
		const std::lock_guard<std::mutex> lock(key);
		counter++;
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