#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
std::mutex m1, m2;

void worker1() {
	std::scoped_lock lk(m1, m2);
	std::cout << "Worker 1 acquired both mutexes" << std::endl;
	std::cout << "Worker 1 processing..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Worker 1 releasing both mutexes" << std::endl;
}

void worker2() {
	std::scoped_lock lk(m1, m2);
	std::cout << "Worker 2 acquired both mutexes" << std::endl;
	std::cout << "Worker 2 processing..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Worker 2 releasing both mutexes" << std::endl;
}


int main() {
	std::thread t1(worker1);
	std::thread t2(worker2);
	t1.join();
	t2.join();
}

