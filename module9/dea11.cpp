#include<iostream>
#include<thread>
#include<mutex>

bool ready = false;
std::mutex mtx;
std::condition_variable cv;

void waiter() {
	std::cout << "waiter waiting to do work" << std::endl;
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [] {return ready;});
	std::cout << "waiter working now..." << std::endl;
}

void signaler() {
	std::unique_lock<std::mutex> lock(mtx);
	std::cout << "signaler working now..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	ready = true;
	cv.notify_one();
}

int main() {
	std::thread t1(waiter);
	std::thread t2(signaler);
	t1.join();
	t2.join();

	return 0;
}