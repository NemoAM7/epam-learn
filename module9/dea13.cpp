#include<iostream>
#include<thread>
#include<semaphore>
#include<mutex>

std::counting_semaphore<2> sem(2);
std::mutex printMtx;

void worker() {
	{
		std::lock_guard<std::mutex> lock(printMtx);
		std::cout << "[" << std::this_thread::get_id() << "] acquiring semaphore." << std::endl;
	}
	sem.acquire();
	{
		std::lock_guard<std::mutex> lock(printMtx);
		std::cout << "[" << std::this_thread::get_id() << "] acquired semaphore." << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));
	{
		std::lock_guard<std::mutex> lock(printMtx);
		std::cout << "[" << std::this_thread::get_id() << "] exiting semaphore." << std::endl;
	}
	sem.release();
	{
		std::lock_guard<std::mutex> lock(printMtx);
		std::cout << "[" << std::this_thread::get_id() << "] exited semaphore." << std::endl;
	}
}

int main() {
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
}