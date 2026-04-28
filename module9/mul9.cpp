#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;

class Logger {
	Logger() {}
public:
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
	static Logger& getInstance() {
		static Logger logger;
		return logger;
	}
	void print() const {
		std::unique_lock<std::mutex> lock(mtx);
		std::cout << "address of object: " << this << ", thread id: " << std::this_thread::get_id() << std::endl;
	}
};

int main() {
	std::thread t1([]() {Logger::getInstance().print();});
	std::thread t2([]() {Logger::getInstance().print();});
	std::thread t3([]() {Logger::getInstance().print();});
	std::thread t4([]() {Logger::getInstance().print();});

	t1.join();
	t2.join();
	t3.join();
	t4.join();

}
