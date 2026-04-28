#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	vector<string> students;
	for (const auto& student : { "Alice", "Bob", "Charlie", "Diana", "Eve" }) {
		students.push_back(student);
	}

	for (const auto& student : students) {
		cout << "Student: " << student << endl;
	}

	if (find(students.begin(), students.end(), "Charlie") != students.end()) {
		students.erase(std::remove(students.begin(), students.end(), "Charlie"), students.end());
	}
	else {
		cout << "Charlie is absent!" << endl;
	}

	for (const auto& student : students) {
		cout << "Student: " << student << endl;
	}

	if (find(students.begin(), students.end(), "Eve") != students.end()) {
		cout << "Eve is present!" << endl;
	}
	else {
		cout << "Eve is absent!" << endl;
	}

	sort(students.begin(), students.end());

	for (const auto& student : students) {
		cout << "Student: " << student << endl;
	}

	students.clear();
	if (students.empty()) cout << "list cleared!" << endl;

	for (const auto& student : students) {
		cout << "Student: " << student << endl;
	}

}