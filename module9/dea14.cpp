#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<queue>
#include<functional>


class ThreadPool {
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;
	std::condition_variable cv;
	std::mutex mtx;
	std::atomic<bool> flag;


public:
	ThreadPool(int N) : flag(false) {
		for (int i = 0; i < N; i++) {
			threads.emplace_back([this]() {
				while (true) {
					std::function<void()> task;
					{
						std::unique_lock<std::mutex> lock(mtx);
						cv.wait(lock, [this] {
							return flag || !tasks.empty();
							});

						if (flag && tasks.empty()) return;

						task = std::move(tasks.front());

						tasks.pop();
					}

					task();
				}
				});
		}
	}

	void submit(std::function<void()> worker) {
		{
			std::unique_lock<std::mutex> lock(mtx);
			tasks.push(std::move(worker));
		}
		cv.notify_one();
	}

	~ThreadPool() {
		flag = true;
		cv.notify_all();
		for (std::thread& worker : threads) {
			worker.join();
		}
	}
};

int main() {
	ThreadPool pool(4); // Create 4 worker threads

	for (int i = 0; i < 8; ++i) {
		pool.submit([i] {
			std::cout << "Task " << i << " is being processed by thread "
				<< std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			});
	}

	// Pool goes out of scope here, triggering the destructor and joining threads
	return 0;
}

