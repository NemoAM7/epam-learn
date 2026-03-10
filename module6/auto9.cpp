#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> vec{ 1,2,3,4,5 };

	cout << "Elements in vec: ";
	for (auto x : vec) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}