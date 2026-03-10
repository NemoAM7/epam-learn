#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

class Numbers {
	vector<int> data;

public:
	Numbers(initializer_list<int> list) : data(list){}
	void print() const {
		cout << "Numbers: ";
		for (auto x : data) {
			cout << x << " ";
		}
		cout << endl;
	}
};

int main(){
	Numbers nums{ 1,2,3,4,5,6 };
	nums.print();
	return 0;
}