#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

class Numbers {
public:
	initializer_list<int> list;
	Numbers(initializer_list<int> ilist) : list(ilist) {}
};

int main() {
	Numbers nums{ 1,2,3,4,5,6 };
	cout << "Numbers: ";
	for (auto x : nums.list) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
