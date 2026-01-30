#include<stdio.h>
#include<string.h>

// Employee struct 
struct Employee {
	char name[50];
	int employee_id;
	float salary;
};

// Prints employee details in a structured format
void printEmployeeDetails(struct Employee emp1) {
	printf("ID: %d\n", emp1.employee_id);
	printf("Name: %s\n", emp1.name);
	printf("Salary: %f\n", emp1.salary);
}

int main() {

	// Example employee
	struct Employee emp1;

	// Employee Name assigned
	strcpy_s(emp1.name, "John Doe");

	// Employee ID assigned
	emp1.employee_id = 100;

	// Employee salary assigned
	emp1.salary = 10.2;

	// display employee 
	printEmployeeDetails(emp1);


	// count of employees
	const int size = 4;

	// Employee struct
	struct Employee staff[size];
	
	// Sample data
	char names[size][50] = { "Ayaan", "Mooli", "Myaan", "Aooli"};
	int salaries[size] = {100.1, 200.2, 300.2, 400.2};

	// Populate structs
	for (int i = 0; i < size; i++) {
		strcpy_s(staff[i].name, names[i]);
		staff[i].employee_id = 100 + i + 1;
		staff[i].salary = salaries[i];
	}

	printf("Employee Details :\n");

	for (int i = 0; i < size; i++) {
		printf("\n");
		printEmployeeDetails(staff[i]);
	}
	
}