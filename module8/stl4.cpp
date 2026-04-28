#include<iostream>
#include<list>
using namespace std;

int main() {
	list<string> WareHouse1 = { "A100", "A200", "A300" };
	list<string> WareHouse2 = { "A150", "A250", "A350" };
	WareHouse1.sort();
	WareHouse2.sort();

	cout << "Size of first WareHouse before merge: " << WareHouse1.size() << endl;
	cout << "Size of second WareHouse before merge: " << WareHouse2.size() << endl;

	for (const auto& item : WareHouse1) {
		cout << item << " ";
	}
	cout << endl;

	for (const auto& item : WareHouse2) {
		cout << item << " ";
	}
	cout << endl;

	WareHouse1.merge(WareHouse2);

	for (const auto& item : WareHouse1) {
		cout << item << " ";
	}
	cout << endl;

	cout << "Size of first WareHouse after merge: " << WareHouse1.size() << endl;
	cout << "Size of second WareHouse after merge: " << WareHouse2.size() << endl;
}