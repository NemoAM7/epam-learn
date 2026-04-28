#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx1, mtx2, mtx3;

void threadA() {
	std::unique_lock<std::mutex> lock1(mtx1);
	std::cout << "Locked mtx1 by thread A" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::unique_lock<std::mutex> lock2(mtx2);
	std::cout << "Locked mtx2 by thread A" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::unique_lock<std::mutex> lock3(mtx3);
	std::cout << "Locked mtx3 by thread A" << std::endl;
}

void threadB() {
	std::unique_lock<std::mutex> lock1(mtx2);
	std::cout << "Locked mtx2 by thread B" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::unique_lock<std::mutex> lock2(mtx3);
	std::cout << "Locked mtx3 by thread B" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::unique_lock<std::mutex> lock3(mtx1);
	std::cout << "Locked mtx1 by thread B" << std::endl;
}

void threadC() {
	std::unique_lock<std::mutex> lock1(mtx3);
	std::cout << "Locked mtx3 by thread C" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::unique_lock<std::mutex> lock2(mtx1);
	std::cout << "Locked mtx1 by thread C" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::unique_lock<std::mutex> lock3(mtx2);
	std::cout << "Locked mtx2 by thread C" << std::endl;
}

void threadX(const string& threadName){
	std::scoped_lock lock(mtx1, mtx2, mtx3);
	std::cout << "Locked mtx3 by thread " << threadName << std::endl;
	std::cout << "Locked mtx1 by thread " << threadName << std::endl;
	std::cout << "Locked mtx2 by thread " << threadName << std::endl;
}

int main() {
	// MUTEX ACCESS ORDER
	// D: 1->2->3, E: 1->2->3, F: 1->2->3
	std::cout << "test" << std::endl;
	t1 = std::thread(threadX, "D"), t2 = std::thread(threadX, "E"), t3 = std::thread(threadX, "F");
	t1.join();
	t2.join();
	t3.join();

	//runs perfectly since each thread have same order or mutex access
	std::cout << "Same order execution finished-----------------------------------\n";
	// MUTEX ACCESS ORDER
	// A: 1->2->3, B: 2->3->1, C: 3->1->2
	std::thread t1(threadA), t2(threadB), t3(threadC);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "Execution still not finished, therefore threads are stuck in a deadlock!" << std::endl;

	t1.join();
	t2.join();
	t3.join();
	// All three threads will be stuck in a triangle deadlock
	// ie. thread A trying to access mtx2 while having mtx1,
	// thread B trying to access mtx3 while having mtx2,
	// thread C trying to access mtx1 while having mtx3
	std::cout << "Different order execution finished-----------------------------------\n";

}