#include<iostream>
#include<thread>
#include<chrono>

void worker() {
	std::cout << "Worker thread started!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
	std::cout << "Completed!" << std::endl;
}

int main() {
	std::thread t1(worker);
	t1.detach();

	std::cout << "Main ends!" << std::endl;
}