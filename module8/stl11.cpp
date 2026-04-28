#include<iostream>
#include<set>
using namespace std;

void populateRoster(set<int>& students) {
	for (int x : {101, 105, 103, 102}) {
		students.insert(x);
	}
}

void populateAndDemonstrateUniqueness(set<int>& students) {
	cout << "Size of set: " << students.size() << endl;
	populateRoster(students);
	cout << "Size of set after populating: " << students.size() << endl;
	students.insert(105);
	cout << "Size of set after duplicate insertion: " << students.size() << endl;
}

void printRoster(const set<int>& students, const string& message) {
	cout << message << endl;
	for (int id : students) {
		cout << id << endl;
	}
}

bool checkIfStudentExists(const set<int>& students, const int student) {
	auto it = students.find(student);
	if (it != students.end()) {
		cout << "Student exists!" << endl;
		return true;
	}

	cout << "Student doesnt exist!" << endl;
	return false;
}

void removeStudents(set<int>& students, const int student) {
	if (checkIfStudentExists(students, student)) {
		students.erase(student);
		cout << "Erased student!" << endl;
	}
}

int main() {
	set<int> students;
	cout << "Student set has been declared, ready to use! \n" << endl;
	populateRoster(students);
	printRoster(students, "Student IDs in the set (initial roster):");
	checkIfStudentExists(students, 102);
	checkIfStudentExists(students, 104);

	removeStudents(students, 104);
	printRoster(students, "State after removing 104");

	removeStudents(students, 102);
	printRoster(students, "Final state after both removals");
	cout << "Size of roster: " << students.size() << endl;
}
