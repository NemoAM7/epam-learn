#include<iostream>
#include<thread>
#include<vector>
#include<string>

void printMessage(const std::string& msg) {
	std::cout << "Message: " << msg << std::endl;
	std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
}

int main() {
	std::vector<std::thread> threads;
	std::vector<std::string> messages = {
		"Message 1", "Message 2", "Message 3", "Message 4", "Message 5"
	};

	for (const std::string& message : messages) {
		threads.emplace_back(std::thread(printMessage, message));
	}
	std::thread t1(printMessage, "test");
	std::thread t2 = move(t1);
	for (std::thread& t : threads) {
		if (t.joinable()) {
			t.join();
		}
	}
}