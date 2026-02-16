#include<iostream>
using namespace std;

// class definition
class Student {
	
	// private student data members
	int rollNo;
	string name;
	char grade;

public:
	
	// public consturctors
	Student() : rollNo(0), name("Unknown"), grade('U') {
		cout << "Default consturctor called" << endl;
	} // default the data members when no parameters are provided

	Student(int r, string n, char g) : rollNo(r), name(n), grade(g) {
		cout << "Parameterized consturctor called" << endl;
	} // assign data members with the values in parameters

	// formatted printing of student details
	void printStudentDetails() {
		cout << "-- Student details --" << endl;
		cout << "Student Roll no.: " << rollNo << endl;
		cout << "Student Name: " << name << endl;
		cout << "Student Grade: " << grade << endl;
	}
};

int main() {
	// declare two Student objects, one is default initialized while other was given parameters
	Student student1, student2(1, "Ayaan", 'B');

	// print the details for both students
	student1.printStudentDetails();
	student2.printStudentDetails();
}