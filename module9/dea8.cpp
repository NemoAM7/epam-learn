#include<iostream>
#include<thread>

std::atomic<int> counter = 0;
volatile int counter2 = 0;

void worker() {
	for (int i = 0; i < 1000; i++) {
		std::this_thread::sleep_for(std::chrono::nanoseconds(10));
		counter.fetch_add(1);
	}
}

void worker2() {
	for (int i = 0; i < 1000; i++) {
		std::this_thread::sleep_for(std::chrono::nanoseconds(10));
		counter2++;
	}
}

int main() {

	std::cout << "Before threads are done Counter (atomic): " << counter << std::endl;

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
	std::cout << "After threads are done Counter (atomic): " << counter << ", Expected: 5000" << std::endl;
	// Increments are atomic thus not causing simultaneous increments (at same nanosecond)

	std::cout << "Before threads are done Counter (volatile): " << counter2 << std::endl;

	t1 = std::thread(worker2);
	t2 = std::thread(worker2);
	t3 = std::thread(worker2);
	t4 = std::thread(worker2);
	t5 = std::thread(worker2);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	std::cout << "After threads are done Counter (volatile): " << counter2 << ", Expected: 5000" << std::endl;
	// Increments are not atomic thus not causing simultaneous increments (at same nanosecond)
	// this is because volatile only prevents CPU optimiztions such as caching if some external source might change the value
	// it doesnt gurantee thread safety since threads can still increment it at same moment (race condition)

}