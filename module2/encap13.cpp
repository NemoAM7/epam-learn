#include<iostream>
#include<vector>
using namespace std;

// Employee base class
class Employee {
	string name;
	int id;

public:
	// constructor to set values
	Employee(string name, int id) : name(name), id(id) {}

	// getters
	string getName() { return name; }

	int getId() { return id; }
	
	// virtual function for polymorphism
	virtual double calculatePay() const = 0;
	
	// display function 
	virtual void display() { cout << name << "-" << id << endl; }
};

// derived salaried class
class SalariedEmployee : public Employee {
	double salary;
public:
	
	// Constructor to set values and construct parent class
	SalariedEmployee(string name, int id, double salary) : Employee(name, id), salary(0) {
		setSalary(salary);
	}
	
	// setter 
	void setSalary(double salary) {
		if (salary < 0) {
			cout << "Salary cannot be less than zero, please update the salary!" << endl;
			salary = 0;
		}

		this->salary = salary;
	}

	// display function
	void display() {
		Employee::display();
		cout << "Salary: " << salary << endl;
	}

	// pay function based on salary
	double calculatePay() const override { return salary; }
};

// derived hourly class
class HourlyEmployee : public Employee {
	double hourlyRate;
	double hoursWorked;
public:
	// constructor
	HourlyEmployee(string name, int id, double hourlyRate, double hoursWorked) : Employee(name, id) {
		setHourlyRate(hourlyRate);
		setHoursWorked(hoursWorked);
	}

	// setters
	void setHoursWorked(double hoursWorked) {
		if (hoursWorked < 0) {
			cout << "hoursWorked cannot be less than zero, please update the hoursWorked!" << endl;
			hoursWorked = 0;
		}

		this->hoursWorked = hoursWorked;
	}

	void setHourlyRate(double hourlyRate) {
		if (hourlyRate < 0) {
			cout << "hourlyRate cannot be less than zero, please update the hourlyRate!" << endl;
			hourlyRate = 0;
		}

		this->hourlyRate = hourlyRate;
	}

	// display function
	void display() {
		Employee::display();
		cout << "Hourly Rate: " << hourlyRate << endl;
		cout << "Hours Worked: " << hoursWorked << endl;
	}

	// calculate pay
	double calculatePay() const override { return hourlyRate * hoursWorked; }
};

int main() {
	// vector of employees
	vector<Employee*> employees;

	// populate employees
	employees.push_back(new HourlyEmployee("Alice", 1, 10, 20));
	employees.push_back(new SalariedEmployee("Bob", 2, 300));
	employees.push_back(new HourlyEmployee("Chris", 3, -20, 30));
	employees.push_back(new SalariedEmployee("Derrick", 4, -200));

	// display each one of them
	for (Employee* emp : employees) {
		emp->display();
	}
}