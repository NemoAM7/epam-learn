#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
#include<condition_variable>

std::mutex m1, m2;

void A() {
	std::cout << "thread A attempting to acquire m1 lock" << std::endl;
	std::unique_lock<std::mutex> lock1(m1);
	std::cout << "thread A acquired m1 lock" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	//deadlock
	std::cout << "thread A attempting to acquire m2 lock" << std::endl;
	std::unique_lock<std::mutex> lock2(m2);
	std::cout << "thread A acquired m2 lock" << std::endl;
}


void B() {
	std::cout << "thread B attempting to acquire m2 lock" << std::endl;
	std::unique_lock<std::mutex> lock1(m2);
	std::cout << "thread B acquired m2 lock" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	//deadlock
	std::cout << "thread B attempting to acquire m1 lock" << std::endl;
	std::unique_lock<std::mutex> lock2(m1);
	std::cout << "thread B acquired m1 lock" << std::endl;
}

int main() {
	std::thread a(A), b(B);
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "Threads have still not acquired resources due to circular wait for mutex resources\n";
	a.join(); b.join();
	return 0;
}