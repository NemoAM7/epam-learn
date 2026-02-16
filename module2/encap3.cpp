// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
	std::string name;
	int rollNo;
	int marks;

public:
	void setName(std::string name);

	void setRollNo(int rollNo);

	void setMarks(int marks);

	std::string getName();

	int getRollNo();

	int getMarks();
};

#endif // STUDENT_H

// Student.cpp

#include "Student.h"
#include<iostream>

void Student::setName(std::string name) {
	this->name = name;
}

void Student::setRollNo(int rollNo) {
	if (rollNo < 0) {
		std::cout << "Roll Number can't be negative" << std::endl;
	}
	this->rollNo = rollNo;
}

void Student::setMarks(int marks) {
	if (0 > marks || marks > 100) {
		std::cout << "Marks must be in range 0-100" << std::endl;
		return;
	}
	this->marks = marks;
}

std::string Student::getName() {
	return name;
}

int Student::getRollNo() {
	return rollNo;
}

int Student::getMarks() {
	return marks;
}

// main.cpp

#include <iostream>
#include "Student.h"

int main() {
	Student student1;

	student1.setName("Ayaan");
	student1.setRollNo(-1);
	student1.setRollNo(1);
	student1.setMarks(101);
	student1.setMarks(95);

	std::cout << "Name : " << student1.getName() << std::endl;
	std::cout << "Roll No. : " << student1.getRollNo() << std::endl;
	std::cout << "Marks : " << student1.getMarks() << std::endl;

	return 0;
}