#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v{ 1,2,3,4,5 };
	for_each(v.begin(), v.end(), [](int& x) {x *= 2;});
	cout << "Updated vector: ";
	for (auto x : v) {
		cout << x << " ";
	}

	cout << endl;
	return 0;
}