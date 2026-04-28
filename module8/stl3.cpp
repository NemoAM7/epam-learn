#include<iostream>
#include<list>
using namespace std;

int main() {
	std::list<int> grades;
	cout << "Is list empty: ";

	if (grades.empty()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


	for (int i = 0; i < 6; i++) {
		grades.push_back(i);
	}

	for (int grade : grades) {
		cout << "Grade: " << grade << endl;
	}

	cout << "Size of list is " << grades.size() << endl;

	cout << "First grade: " << grades.front() << endl;
	cout << "Second grade: " << grades.back() << endl;

	auto it = grades.begin();
	std::advance(it, 2);

	cout << "Grade at index 2: " << *it << endl;
	*it = 99;

	unsigned int index;
	cout << "Grade at index: ";
	cin >> index;

	it = grades.begin();
	if (index >= grades.size()) {
		cout << "Index out of bound." << endl;
	}
	else {
		std::advance(it, index);
		cout << "Grade index " << index << ": " << *it << endl;
	}

	grades.push_front(7);
	grades.push_back(8);
	it = grades.begin();

	for (unsigned int i = 0; i < grades.size(); i++) {
		cout << "Grade at index " << i << ": " << *it << endl;
		std::advance(it, 1);
	}

	grades.pop_back();
	it = grades.begin();
	grades.

		grades.clear();

	cout << "Size of list after clearing: " << grades.size() << endl;

	if (grades.empty()) {
		cout << "List is empty" << endl;
	}

	return 0;
}