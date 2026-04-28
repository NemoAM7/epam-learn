#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mtx;

class Logger {
private:
	inline static Logger* instance = nullptr;
	inline static std::once_flag flag;

	Logger() {}
public:
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	static Logger& getInstance() {
		std::call_once(flag, []() { instance = new Logger();});
		return *instance;
	}

	void print() const {
		std::unique_lock<std::mutex> lock(mtx);
		std::cout << "Logger: " << this << ", Thread: " << std::this_thread::get_id() << std::endl;
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


