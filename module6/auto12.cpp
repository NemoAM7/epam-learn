#include<iostream>
#include<vector>

using namespace std;


int main() {
	vector<vector<int>> mat{ {1,2}, {3,4} };

	cout << "Matrix elements: " << endl;
	for (const auto& row : mat) {
		for (auto val : row) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}