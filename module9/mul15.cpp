#include<iostream>
#include<thread>
#include<future>
#include<mutex>

std::mutex mtx;

void worker(std::promise<int>&& p) {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	p.set_value(99);
}

int main() {
	std::promise<int> p;
	std::future<int> fut = p.get_future();
	std::thread t1(worker, std::move(p)); //passes the ownership of promise to the worker thread
	t1.detach();
	int result = fut.get(); // main thread goes into waiting to recieve the promise 
	std::cout << "Value recieved: " << result << std::endl;
}