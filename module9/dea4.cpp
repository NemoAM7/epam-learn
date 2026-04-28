#include<iostream>
#include<thread>

int counter = 0;

void worker() {
	for (int i = 0; i < 1000; i++) {
		counter++;
	}
}
int main() {

	std::cout << "Before threads are done Counter: " << counter << std::endl;

	std::thread t1(worker);
	std::thread t2(worker);
	std::thread t3(worker);
	std::thread t4(worker);
	std::thread t5(worker);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	std::cout << "After threads are done Counter: " << counter << ", Expected: 5000" << std::endl;
	// Increments are not atomic thus causing simultaneous increments (at same nanosecond)
	// causing race condition and thus undercounting the actual value
	// std::atomic<int> can fix this by using a lock free mechanism where operations on counter will be atomic
}