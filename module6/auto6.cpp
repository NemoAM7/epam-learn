#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v{ 1,2,3,4,5 };
	for (auto& x : v) {
		x *= 2;
	}

	cout << "Modified vector (by reference): ";
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;

	v = { 1,2,3,4,5 };
	for (auto x : v) {
		x *= 2;
	}

	cout << "Value based loop (no modifiation): ";
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}