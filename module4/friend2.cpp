#include<iostream>
using namespace std;

class Student {
	string name;
	double marks;
public:
	Student(string name, double marks) : name(name), marks(marks) {}
	friend class Result;
};

class Result {
public:
	void display(const Student& student) {
		cout << "Name : " << student.name << endl;
		cout << "Marks : " << student.marks << endl;
		cout << "Status : " << (student.marks <= 33 ? "Failed" : "Passed") << endl;
	}
};

int main() {
	Result result;


	Student s("Alice", 72);
	result.display(s);

	Student s2("Bob", 32);
	result.display(s2);
}