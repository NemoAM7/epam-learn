#include<stdio.h>
#include<stdlib.h>
#include <cstring>

// Student struct
struct Student {
	int rollNo;
	char name[50];
	float marks;
};

// Gets rollno, name and marks of a student from user and writes it into a dat file
void addStudentRecord() {

	// struct for new student
	struct Student newStudent;
	
	// temporary student variables
	int rollNo;
	char name[50];
	float marks;

	// variable for clearing buffer
	char c;

	// clearing buffer before string input
	while ((c = getchar()) != '\n' && c != EOF);

	printf("\n");

	// get student name from user 
	printf("Enter Name of student: ");

	// check if input is valid
	if (fgets(name, sizeof(newStudent.name), stdin) == NULL) {
		printf("Invalid Student!");
		return;
	}

	// get student roll no from user
	printf("Enter the Roll No. of student: ");

	// check if the input is valid
	if (scanf_s("%d", &rollNo) != 1 || rollNo <= 0) {
		printf("Invalid Roll No, must be a positive integer!");
		return;
	}

	// get student marks from user
	printf("Enter the marks of student [0, 100]: ");

	// check if the input is valid
	if (scanf_s("%f", &marks) != 1 || marks > 100 || marks < 0) {
		printf("Invalid Marks, must be an integer between 0 and 100");
		return;
	}

	// copy the temporary details into the student struct
	strcpy_s(newStudent.name, name);
	newStudent.rollNo = rollNo;
	newStudent.marks = marks;

	// variable for the file pointer
	FILE* fptr = NULL;

	// variable for error status code while opening file
	int err = fopen_s(&fptr, "students.dat", "ab");

	// check if there was an error while opening the file
	if (err != 0) {
		printf("Error while opening the file!");
		return;
	}

	// write the student struct into the file
	// check whether the struct was written succesfully 
	if (fwrite(&newStudent, sizeof(newStudent), 1, fptr) == 1) {
		printf("Structure written successfully\n");
	}
	else {
		printf("Error while writing to the file!");
	}

	// close the file pointer
	fclose(fptr);
	fptr = NULL;
}

// displays all the records stored in the student dat file
void displayAllRecords() {
	
	// variable for the file pointer
	FILE* fptr = NULL;

	// variable for error status code while opening the file
	int err = fopen_s(&fptr, "students.dat", "rb");

	// check if there was an error while opening the file
	if (err != 0) {
		printf("Error while opening the file!");
		return;
	}
	
	// struct to read the student file data
	struct Student fileData;

	// loop till we reach end of file and print the data
	while (fread(&fileData, sizeof(struct Student), 1, fptr)) {
		printf("\n");
		printf("Roll no\t: %d\n", fileData.rollNo);
		printf("Name\t: %s", fileData.name);
		printf("Marks\t: %.2f\n", fileData.marks);
	}
	
	//close the file pointer
	fclose(fptr);
	fptr = NULL;

}

int main() {
	
	int choice;
	while (1) {
		printf("\nStudent record system. Choose an option.\n 1. Add a student\n 2. Display all students\n 3. Exit the program.\nchoice : ");
		if (scanf_s("%d", &choice) != 1) {
			printf("Invalid input. Exiting..");
			return 1;
		}

		switch (choice) {
		case 1:
			addStudentRecord();
			break;
		case 2:
			displayAllRecords();
			break;
		case 3:
			printf("Thank you for using! Exitting..");
			return 0;
		default:
			printf("Unknown option. Exiting..");
			return 0;
		}
	}

	return 0;
}
