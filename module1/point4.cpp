#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

// Employee Struct
struct Employee {
	int id;
	char name[50];
	float salary;
};


// Prints employee detials in a structured format
void printEmployeeDetails(struct Employee* emp1) {
	printf("ID: %d\n", emp1->id);
	printf("Name: %s\n", emp1->name);
	printf("Salary: %f\n", emp1->salary);
}

int main() {
  
  // Allocate memory for a single employee using dynamic memeory allocation
	struct Employee* empPtr = (struct Employee*)malloc(sizeof(struct Employee));
	
	if (empPtr == NULL) {
	  printf("Unable to allocate memory for the employee!\n");
	  return 1;
	}
	
	// Temporary variable for copying purposes
	char temp[50];
	
	// Input fields
	printf("Enter employee ID: ");
	scanf("%d", &empPtr->id);

	printf("Enter employee Name: ");
	scanf("%s", temp);

	strcpy(empPtr->name, temp);

	printf("Enter employee salary: ");
	scanf("%f", &empPtr->salary);

  // Print original employee details
	printEmployeeDetails(empPtr);
	
	//Ask for salary update
	printf("Enter the updated salary amount: ");
	scanf("%f", &empPtr->salary);
	
	printf("Updated salary!\n");
	
	// Print updated salary
	printEmployeeDetails(empPtr);
	
	// free up the allocated space for memory after use
	free(empPtr);
	
	return 0;
}