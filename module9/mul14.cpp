#include<iostream>
#include<thread>
#include<future>
#include<mutex>

std::mutex mtx;

int longComputation() {
	std::unique_lock<std::mutex> lock(mtx);
	std::cout << "Starting long computation!" << std::endl;
	lock.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	return 42;
}

int main() {
	std::future<int> fut = std::async(std::launch::async, longComputation);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	std::unique_lock<std::mutex> lock(mtx);
	std::cout << "processing further in main..." << std::endl;
	lock.unlock();
	int result = fut.get();
	std::cout << "result from future task after async thread execution: " << result << std::endl;
}