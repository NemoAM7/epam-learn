#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int factor = 3;
	vector<int> v{ 1,2,3 };
	for_each(v.begin(), v.end(), [factor](int& x) {x *= factor;});
	cout << "After value capture lambda (factor = 3) ";
	for (auto x : v) cout << x << " ";
	cout << endl;


	factor = 10;
	for_each(v.begin(), v.end(), [&factor](int& x) {x *= factor;});
	cout << "After reference capture lambda (factor = 10) ";
	for (auto x : v) cout << x << " ";
	cout << endl;

	return 0;
}