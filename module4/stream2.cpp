#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
	vector<string> names;
	vector<double> prices;

	names.push_back("Apple");
	names.push_back("Orange");
	names.push_back("Banana");

	prices.push_back(100.214);
	prices.push_back(30.1);
	prices.push_back(40);

	cout << fixed << setprecision(2);

	cout << setw(10) << "Item" << setw(10) << "Price" << endl;

	for (int i = 0; i < names.size(); i++) {
		cout << setw(10) << names[i] << setw(10) << prices[i] << endl;
	}

}