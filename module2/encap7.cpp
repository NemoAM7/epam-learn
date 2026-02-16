#include<string>
#include<iostream>

using namespace std;

// Person base class
class Person {
	string name;
	int age;

public:

	// Setters and getters for name and age
	void setName(string name) {
		this->name = name;
	}

	void setAge(int age) {
		this->age = age;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}
};

// Student derived class
class Student : public Person {
	int rollNo;
	char grade;

public:

	// Setters for roll number and grade
	void setRollNo(int rollNo) {
		this->rollNo = rollNo;
	}

	void setGrade(char grade) {
		this->grade = grade;
	}

	// Display function to show student details
	void display() {
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Roll No: " << rollNo << endl;
		cout << "Grade: " << grade << endl;
	}
};

// Teacher derived class
class Teacher : public Person {
	string subject;
	double salary;

public:

	// Setters for subject and salary
	void setSubject(string subject) {
		this->subject = subject;
	}

	void setSalary(double salary) {
		this->salary = salary;
	}

	// Display function to show teacher details
	void display() {
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Subject: " << subject << endl;
		cout << "Salary: " << salary << endl;
	}
};


int main() {
	// Creating instances of Student and Teacher
	Student student;
	Teacher teacher;

	// Setting values for student and teacher
	student.setName("Mooli");
	student.setAge(20);
	student.setRollNo(21);
	student.setGrade('O');

	teacher.setName("Nooli");
	teacher.setAge(40);
	teacher.setSubject("Algorithms");
	teacher.setSalary(60000);

	// Displaying details of student and teacher
	student.display();
	teacher.display();
}
