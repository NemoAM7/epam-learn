
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct MultiplyBy {
	int factor;
	void operator()(int& x) const { x *= factor; }
};

int main() {
	vector<int> v{ 1,2,3,4,5 };
	for_each(v.begin(), v.end(), MultiplyBy(3));
	cout << "Modified vector: ";
	for (int n : v) {
		cout << n << " ";
	}
	cout << endl;
	return 0;

}


