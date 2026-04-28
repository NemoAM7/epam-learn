#include<iostream>
#include<thread>
#include<mutex>
#include<barrier>

std::barrier b{ 3 };

void worker(const string& threadNo) {
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Thread " << threadNo << "before barrier working in Phase 1" << std::endl;
	b.arrive_and_wait();
	std::cout << "Thread " << threadNo << "after barrier working in Phase 2" << std::endl;
}

int main() {
	std::thread t1(worker);
	std::thread t2(worker);
	std::thread t3(worker);
	//std::thread t4(worker);

	t1.join();
	t2.join();
	t3.join();
	//t4.join();
}