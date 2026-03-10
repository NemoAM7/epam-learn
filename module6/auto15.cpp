#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

class Matrix {
	vector<vector<int>> data;

public:
	Matrix(initializer_list<initializer_list<int>> list) {
		for (const auto& row : list) {
			data.emplace_back(row);
		}
	}
	
	void printAndDouble() {
		cout << "Printing Matrix: " << endl;
		for (auto& row : data) {
			for (auto& col : row) {
				cout << col << " ";
				col *= 2;
			}
			cout << endl;
		}
		cout << endl;
	}

	void print() const {
		cout << "Printing Matrix: " << endl;
		for (auto& row : data) {
			for (auto& col : row) {
				cout << col << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
	Matrix mat{
		{1, 2},
		{3, 4}
	};
	
	mat.printAndDouble();
	cout << "After doubling" << endl;
	mat.print();
}
