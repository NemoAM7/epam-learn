#include<iostream>
#include<thread>
#include<chrono>
#include<condition_variable>
#include<mutex>

int counter = 1;
std::mutex mtx;
std::condition_variable cv;
const int MAX = 20;

void odd() {
	while (true) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return counter % 2 == 1 || counter > MAX;});
		if (counter > MAX) {
			cv.notify_one();
			break;
		}
		std::cout << "odd: " << counter++ << std::endl;
		cv.notify_one();
	}
}

void even() {
	while (true) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return counter % 2 == 0 || counter > MAX;});
		if (counter > MAX) {
			cv.notify_one();
			break;
		}
		std::cout << "even: " << counter++ << std::endl;
		cv.notify_one();
	}
}

int main() {
	std::thread t1(odd);
	std::thread t2(even);
	t1.join();
	t2.join();
}

