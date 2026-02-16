#include<iostream>
#include<vector>
using namespace std;

class Employee {
	string name;
	int id;

public:
	Employee(string name, int id) : name(name), id(id){}

	virtual double calculatePay() const = 0;

	virtual void display() {
		cout << "Name : " << name << " | " << "ID : " << id << " | ";
	}
};


class SalariedEmployee : public Employee{
	double salary;
public:
	SalariedEmployee(string name, int id, double salary) : Employee(name, id), salary(salary){}

	double calculatePay() const override {
		return salary;
	}

	void display() {
		Employee::display();
		cout << "Pay : " << calculatePay() << endl;
	}
};

class HourlyEmployee : public Employee{
	double hourlyRate;
	double hoursWorked;
public:
	HourlyEmployee(string name, int id, double hourlyRate, double hoursWorked) : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

	double calculatePay() const override {
		return hourlyRate * hoursWorked;
	}
	void display() {
		Employee::display();
		cout << "Pay : " << calculatePay() << endl;
	}
};


int main(){
	vector<Employee*> employees;

	employees.push_back(new SalariedEmployee("Alice", 1, 2));
	employees.push_back(new SalariedEmployee("Bob", 2, 3));
	employees.push_back(new SalariedEmployee("Chris", 3, 4));
	employees.push_back(new SalariedEmployee("Derrick", 4, 5));

	employees.push_back(new HourlyEmployee("Eric", 8, 2, 3));
	employees.push_back(new HourlyEmployee("Fred", 5, 3, 3));
	employees.push_back(new HourlyEmployee("Gennady", 6, 2, 4));
	employees.push_back(new HourlyEmployee("Holmer", 7, 2, 1));

	for (Employee* emp : employees) {
		emp->display();
	}

	for (Employee* emp : employees) {
		delete emp;
	}
}