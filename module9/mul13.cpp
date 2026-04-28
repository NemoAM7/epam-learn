#include<iostream>
#include<mutex>
#include<chrono>

std::mutex mtx1;
std::mutex mtx2;

void worker1() {
	std::unique_lock<std::mutex> lock1(mtx1);
	std::cout << "worker 1 acquired mtx1 and not waiting for mtx2" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::unique_lock<std::mutex> lock2(mtx2);
	std::cout << "worker 1 acquired mtx2" << std::endl;

}

void worker2() {
	std::unique_lock<std::mutex> lock2(mtx2);
	std::cout << "worker 2 acquired mtx2 and now waiting for mtx1" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::unique_lock<std::mutex> lock1(mtx1);
	std::cout << "worker 2 acquired mtx1" << std::endl;
}

std::mutex mtx3;
std::mutex mtx4;

void worker3() {
	std::scoped_lock lock(mtx3, mtx4);
	std::cout << "worker 3 acquired mtx3 and mtx4" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

}

void worker4() {
	std::scoped_lock lock(mtx3, mtx4);
	std::cout << "worker 4 acquired mtx3 and mtx4" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main() {
	// will cause dead lock
	std::thread t1(worker1);
	std::thread t2(worker2);

	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "worker 1 and worker 2 is now deadlocked.Notice they are still waiting for acquiring the mutex." << std::endl;

	t1.detach();
	t2.detach();

	// prevents circular wait by using scoped_lock esentially giving all the required locks atomically
	t1 = std::thread(worker3);
	t2 = std::thread(worker4);

	t1.join();
	t2.join();
}