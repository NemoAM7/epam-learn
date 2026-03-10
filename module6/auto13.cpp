#include<iostream>
#include<vector>

using namespace std;

vector<int> getNumbers(){
	return {1,2,3,4,5};
}

int main() {
	auto nums = getNumbers();
	cout << "Returned Numbers: " << endl;
	for (auto n : nums) {
		cout << n << " ";
	}
	cout << endl;

	return 0;
}