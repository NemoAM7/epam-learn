#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


struct Employee {
	int id;
	char name[50];
	float salary;
};

void printEmployeeDetails(struct Employee* emp1) {
	printf("ID: %d\n", emp1->id);
	printf("Name: %s\n", emp1->name);
	printf("Salary: %f\n", emp1->salary);
}

int main() {
	struct Employee* empPtr = (struct Employee*)malloc(sizeof(struct Employee));
	
	char temp[50];
	
	printf("Enter employee ID: ");
	scanf("%d", &empPtr->id);

	printf("Enter employee Name: ");
	scanf("%s", temp);

	strcpy(empPtr->name, temp);

	printf("Enter employee salary: ");
	scanf("%f", &empPtr->salary);

	printEmployeeDetails(empPtr);
	
	printf("Enter the updated salary amount: ");
	scanf("%f", &empPtr->salary);
	
	printf("Updated salary!\n");
	printEmployeeDetails(empPtr);
	
	free(empPtr);
}