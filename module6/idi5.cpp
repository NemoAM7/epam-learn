#include<iostream>
#include<chrono>

using namespace std;

class Timer {
	chrono::high_resolution_clock::time_point start;
	string label;
public:
	Timer(const string& label) : start(chrono::high_resolution_clock::now()), label(label) {
		if (!label.empty()) cout << "Timer started!: " << label << endl;
	}

	~Timer() {
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

		cout << (label.empty() ? "Elapsed time: " : "Timer[" + label + "] elapsed: ");
		cout << duration.count() << "us" << endl;
	}
};

int main() {
	{
		Timer t("test timer");
	}
	{
		Timer t("Loop block timing");
		int sum = 0;
		for (int i = 0; i < 1000;i++) {
			sum += i;
		}
		cout << sum << endl;
	}
	return 0;
}