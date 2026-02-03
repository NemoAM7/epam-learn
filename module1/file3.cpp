#include<stdio.h>
#include<string>
#include<stdlib.h>

// forward declaration for functions
void appendAttendance(int empId, char timeStamp[]);
void displayAttendanceLog();
void inputAttendance();

// main 
int main()
{
	int count = 0;
	printf("How many people: ");

	// get count of attendance from user and validate it
	if (scanf_s("%d", &count) != 1 || count <= 0) {
		printf("Invalid count, must be a positive integer.\n");
		return 1;
	}
	
	// get attendance for each person
	for (int i = 0; i < count; i++) {
		inputAttendance();
	}

	// display attendance logs
	displayAttendanceLog();

	return 0;
}


// function to take attendance input from user
void inputAttendance() {
	// employee attendance log variables
	int empId;
	char timestamp[30];

	// get the employee id from user
	printf("Enter Employee ID: ");

	// check if employee ID is valid
	if (scanf_s("%d", &empId) != 1 || empId <= 0) {
		printf("Invalid ID, must be a positive integer.\n");
		return;
	}

	// remove new line character before getting string input
	getchar();

	// get the timestamp for attendance from the user
	printf("Enter Timestamp (e.g. 2025-09-20 09:30 AM): ");

	// check whether attendance is valid 
	if (fgets(timestamp, sizeof(timestamp), stdin) == NULL) {
		printf("Invalid Timestamp.\n");
		return;
	}

	// call functions to log the attedance and display
	appendAttendance(empId, timestamp);
}

// function to append attendance log for an employee
void appendAttendance(int empId, char timeStamp[]) {
	
	// file pointer
	FILE* file = NULL;

	// error status code while opening the file in append mode
	int err = fopen_s(&file, "attendance.txt", "a");

	// check if there is an error while opening file
	if (err != 0) {
		printf("Error while appending in the file!\n");
		return;
	}

	// write the log into the file
	fprintf(file, "%d %s\n", empId, timeStamp);

	// close the file
	fclose(file);
	file = NULL;
}

// function to display all the attendance log stored in the log file
void displayAttendanceLog() {

	// file pointer
	FILE* file = NULL;

	// temporary variable to store the read data
	char fileData[50];
	
	// error status code while opening the file in read mode
	int err = fopen_s(&file, "attendance.txt", "r");

	// check if there is an error while opening file
	if (err != 0) {
		printf("Error while reading the file!\n");
	}

	// print the data in file till EOF is reached
	while (fgets(fileData, sizeof(fileData), file)) {
		printf("%s", fileData);
	}

	// close the file
	fclose(file);
	file = NULL;
}
