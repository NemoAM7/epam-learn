#include<iostream>
using namespace std;

class Person {
protected:
	string name;
	int id;

public:
	virtual void displayInfo() const = 0;

};

class Student : virtual public Person {
protected:
	int rollNo;
};


class Employee : virtual public Person {
protected:
	double salary;
};

class TeachingAssistant : public Student, public Employee {
public:
	TeachingAssistant(string n, int i, int r, double s) {
		name = n;
		id = i;
		rollNo = r;
		salary = s;
	}

	void displayInfo () const override {
		cout << "Name : " << name;
		cout << "ID : " << id;
		cout << "Roll No : " << rollNo;
		cout << "Salary : " << salary;
	}
};

int main() {
	TeachingAssistant t("ayaan", 1, 2, 3);
	t.displayInfo();
}