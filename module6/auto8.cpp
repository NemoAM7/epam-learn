
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	vector<pair<int, string>> v{ {1, "A"}, {2, "B"} };
	for (auto& [num, str] : v) {
		cout << "num: " << num << ", str: " << str << endl;
	}
	return 0;
}