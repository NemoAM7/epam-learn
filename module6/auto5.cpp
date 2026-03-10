#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v{ 1,2,3,4,5 };
	cout << "Range based for: ";
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;

	cout << "Iterator based for: ";
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}