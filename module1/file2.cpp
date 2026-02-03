#include<stdio.h>
#include<string>
#include<stdlib.h>

struct Employee {
	int empId;
	char name[50];
	float basicSalary;
};

// Gets empId, name and salary of an employee from user and writes it into a dat file
void addEmployeeRecord() {

	// struct for new employee
	struct Employee newEmployee;

	// temporary employee variables
	int empId;
	char name[50];
	float salary;

	printf("\n");

	// get employee name from user 
	printf("Enter Name of employee: ");

	// check if input is valid
	if (fgets(name, sizeof(newEmployee.name), stdin) == NULL) {
		printf("Invalid Name for Employee!");
		return;
	}

	// get employee ID from user
	printf("Enter the Employee ID of employee: ");

	// check if the input is valid
	if (scanf_s("%d", &empId) != 1 || empId <= 0) {
		printf("Invalid Employee ID, must be a positive integer!");
		return;
	}

	// get employee salary from user
	printf("Enter the base salary of the employee : ");

	// check if the input is valid
	if (scanf_s("%f", &salary) != 1 || salary <= 0) {
		printf("Invalid Salary, must be a positive integer!");
		return;
	}

	// copy the temporary details into the employee struct
	strcpy_s(newEmployee.name, name);
	newEmployee.empId = empId;
	newEmployee.basicSalary = salary;

	// variable for the file pointer
	FILE* fptr = NULL;

	// variable for error status code while opening file
	int err = fopen_s(&fptr, "employee.dat", "ab");

	// check if there was an error while opening the file
	if (err != 0) {
		printf("Error while opening the file!");
		return;
	}

	// write the student struct into the file
	// check whether the struct was written succesfully 
	if (fwrite(&newEmployee, sizeof(newEmployee), 1, fptr) == 1) {
		printf("Structure written successfully\n");
	}
	else {
		printf("Error while writing to the file!");
	}

	// close the file pointer
	fclose(fptr);
	fptr = NULL;
}

// function to generate the salary slip
void generateSalarySlip(struct Employee employee) {

	// calculate allowance and net salary
	float DA = employee.basicSalary * 0.2;
	float HRA = employee.basicSalary * 0.1;
	float netSalary = employee.basicSalary + DA + HRA;

	// temporary variable to store file name for a particular employee
	char fileName[20];
	sprintf_s(fileName, "emp%d_slip.txt", employee.empId);

	// file pointer to write the salary slip
	FILE* fptr = NULL;

	// variable to store error status code while opening the file
	int err = fopen_s(&fptr, fileName, "w");
	
	// check whether there was an error while opening the file
	if (err != 0) {
		printf("Error while opening the file for employee id : %d!", employee.empId);
		return;
	}

	// print the salary slip data to the designated file for the employee
	fprintf(fptr, "Salary Slip for Employee %s (ID: %d)\n", employee.name, employee.empId);
	fprintf(fptr, "-----------------------------------------\n");
	fprintf(fptr, "Basic Salary: %.2f\n", employee.basicSalary);
	fprintf(fptr, "Dearness Allowance (DA): %.2f\n", DA);
	fprintf(fptr, "House Rent Allowance (HRA): %.2f\n", HRA);
	fprintf(fptr, "Net Salary: %.2f\n", netSalary);
	fprintf(fptr, "-----------------------------------------\n");

	// close the file pointer
	fclose(fptr);
	fptr = NULL;
	
}

void processEmployeeRecords() {
	
	// employee struct to read file
	struct Employee employee;

	// file pointer to read file
	FILE* fptr = NULL;

	// error status code while opening file
	int err = fopen_s(&fptr, "employee.dat", "rb");

	// check if there was an error while opening file
	if (err != 0) {
		printf("Error while opening the file!");
		return;
	}

	// read till reach end of file
	while (fread(&employee, sizeof(struct Employee), 1, fptr)) {
		generateSalarySlip(employee); // generate salary slip for each employee
	}

	// close the file pointer
	fclose(fptr);
	fptr = NULL;
}

int main() {
	addEmployeeRecord();
	processEmployeeRecords();
}