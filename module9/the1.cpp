#include<iostream>
#include<mutex>
#include<chrono>
#include<condition_variable>
#include<queue>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool done = false;
int MAX_SIZE = 6;

void producer() {
	for (int i = 0; i < 20; i++) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return buffer.size() < MAX_SIZE;});
		buffer.push(i);
		std::cout << "[Producer] produced: " << buffer.back() << std::endl;
		std::cout << "[Producer] items in buffer: " << buffer.size() << std::endl;
		lock.unlock();
		cv.notify_one();
	}
	std::unique_lock<std::mutex> lock(mtx);
	done = true;
	lock.unlock();
	cv.notify_one();
}


void consumer() {
	while (true) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, []() {return done || !buffer.empty();});
		if (done && buffer.empty()) break;
		std::cout << "[Consumer] consumed: " << buffer.front() << std::endl;
		buffer.pop();
		std::cout << "[Consumer] items in buffer: " << buffer.size() << std::endl;
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