#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;
int counter = 0;

void worker() {
	for (int i = 0; i < 1000; i++) {
		{
			std::lock_guard<std::mutex> lock(mtx);
			++counter;
		}
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
	// Increments are now atomic because of mutex wrapper thus not causing simultaneous increments (at same nanosecond)
}