#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<optional>
#include<chrono>

std::optional<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool finished = false;

void producer() {
	for (int i = 0; i < 10; i++) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return !buffer.has_value();});

		buffer = i + 1;
		std::cout << "Produced: " << i + 1 << std::endl;
		lock.unlock();
		cv.notify_one();
	}

	std::unique_lock<std::mutex> lock(mtx);
	finished = true;
	lock.unlock();
	cv.notify_one();
}

void consumer() {
	while (true) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return buffer.has_value() || finished; });

		if (finished && !buffer.has_value()) break;

		std::cout << "Consumed: " << *buffer << std::endl;
		buffer.reset();
		lock.unlock();
		cv.notify_one();
	}
}

int main() {
	std::thread t1(producer);
	std::thread t2(consumer);

	t1.join();
	t2.join();

	return 0;
}