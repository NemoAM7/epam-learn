#include<iostream>
#include<vector>
#include<thread>

void worker(int chunk, int left, int right, std::vector<int>& sample, std::atomic<int>& store) {
	int localsm = 0;
	for (int i = left; i < right; i++) {
		localsm += sample[i];
	}
	store += localsm;
}

int main() {
	int chunks = std::thread::hardware_concurrency();
	if (chunks == 0) chunks = 2;

	std::vector<int> sample(10000000, 1);
	std::atomic<int> sm = 0;

	int sz = sample.size();
	std::vector<std::thread> threads;
	for (int chunk = 0; chunk < chunks; chunk++) {
		int left = (chunk * sz / chunks);
		int right = ((chunk + 1) * sz / chunks);
		threads.emplace_back(worker, chunk, left, right, std::ref(sample), std::ref(sm));
	}

	for (std::thread& t : threads) t.join();

	int fullSm = 0;
	for (int element : sample) {
		fullSm += element;
	}
	std::cout << "Parralel sum: " << sm << ", Linear sum: " << fullSm << std::endl;
}