#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<optional>
#include<queue>


std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool finished = false;

void producer() {
	for (int i = 0; i < 20; i++) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return buffer.size() < 5;});

		buffer.push(i + 1);
		std::cout << "Produced: " << i + 1;
		std::cout << " [Items left: " << buffer.size() << "]" << std::endl;

		lock.unlock();
		cv.notify_one();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	std::unique_lock<std::mutex> lock(mtx);
	finished = true;
	lock.unlock();
	cv.notify_one();
}

void consumer() {

	std::this_thread::sleep_for(std::chrono::milliseconds(50));

	while (true) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return !buffer.empty() || finished; });

		if (finished && buffer.empty()) break;

		std::cout << "Consumed: " << buffer.front();
		std::cout << " [Items left: " << buffer.size() << "]" << std::endl;
		buffer.pop();

		lock.unlock();
		cv.notify_one();

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

int main() {
	std::thread t1(producer);
	std::thread t2(consumer);

	t1.join();
	t2.join();

	return 0;
}