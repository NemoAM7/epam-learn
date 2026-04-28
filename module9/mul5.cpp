#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

int counter = 0;

std::mutex key;

void incrLockGuard() {
	for (int i = 0; i < 10000; i++) {
		const std::lock_guard<std::mutex> lock(key);
		counter++;
	}
}

void incrUniqueLock() {
	for (int i = 0; i < 10000; i++) {
		const std::unique_lock<std::mutex> lock(key);
		counter++;
		// Could call lock.unlock(), relock(), etc. here if needed.
	}
}

int main() {
	std::thread t1 = std::thread(incrLockGuard);
	std::thread t2 = std::thread(incrUniqueLock);
	std::thread t3 = std::thread(incrLockGuard);
	std::thread t4 = std::thread(incrUniqueLock);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	std::cout << "Counter: " << counter << std::endl;
}