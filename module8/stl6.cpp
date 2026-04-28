#include<iostream>
#include<list>

using namespace std;

int main() {
	std::list<int> numbers;

	for (const int& val : { 3, 5, 7, 3, 5, 7 ,8,9,0,1 }) {
		numbers.push_back(val);
	}

	cout << "Before removal, Printing.." << endl;
	for (const auto& val : numbers) {
		cout << val << endl;
	}

	int value;
	cout << "Which integer should I remove from the list ?" << endl;
	cin >> value;

	numbers.remove(value);

	cout << "After removal, Printing.." << endl;
	for (const auto& val : numbers) {
		cout << val << endl;
	}

	cout << "Which integer should I remove from the list ?" << endl;
	cin >> value;

	auto it = numbers.begin();
	while (it != numbers.end()) {
		if (*it == value) {
			it = numbers.erase(it);
		}
		else {
			++it;
		}
	}

	cout << "After Removal2, Printing.." << endl;
	for (const auto& val : numbers) {
		cout << val << endl;
	}

	if (numbers.empty()) { cout << "Numbers is empty!" << endl; }
	else { cout << "Not empty!" << endl; }



}