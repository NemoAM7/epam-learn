#include<iostream>
#include<mutex>
#include<exception>
#include<thread>
#include<vector>

using namespace std;


int counter = 0;
mutex mtx;

void func(int ITERS) {
	for (int i = 0; i < ITERS; i++) {
		lock_guard<mutex> lock(mtx);
		if (i == 42) throw runtime_error("unnamed exception!");
		counter++;
	}
}
int main() {
	const int THREADS = 4;
	const int ITERS = 1000000;
	vector<thread> tg;

	for (int i = 0; i < THREADS; i++) {
		tg.emplace_back(func, ITERS);
	}

	for (auto& t : tg) {
		t.join();
	}

	cout << "Counter: " << counter << endl;

	return 0;
}
