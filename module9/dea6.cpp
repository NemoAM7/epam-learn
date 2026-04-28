#include<iostream>
#include<thread>
#include<shared_mutex>

std::shared_mutex rw_mtx;
std::string sharedStr = "Start";

void producer() {
	for (int i = 60; i < 100; i++) {
		{
			std::unique_lock<std::shared_mutex> lock(rw_mtx);
			std::cout << "[Producer]: Produced:" << static_cast<char>(i) << std::endl;
			sharedStr.push_back(static_cast<char>(i));
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}

void consumer() {
	for (int i = 0; i < 100; i++) {
		{
			std::shared_lock<std::shared_mutex> lock(rw_mtx);
			std::cout << "[Consumer]: Printing" << sharedStr << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}

int main() {
	std::thread t1(producer);
	std::thread t2(consumer);
	std::thread t3(consumer);
	std::thread t4(consumer);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}