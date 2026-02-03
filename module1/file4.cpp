#include<stdio.h>
#include<string>
#include<stdlib.h>

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

	// add some dummy records
	addStudentRecord();
	addStudentRecord();

	// display any record before update
	displayAllRecords();

	// pointer for file to update
	FILE* file = NULL;

	// student struct for reading data
	struct Student student;

	// variable for search query
	int rollNoSearchQuery;

	// error status code while opening file in r+b mode
	int err = fopen_s(&file, "students.dat", "r+b");

	// check if there is an error while opening the file
	if (err != 0) {
		printf("Error while opening the file in r+b mode!\n");
		return 1;
	}

	// get the roll no search query from the user
	printf("Enter the Roll No. to update: ");

	// check if roll no search query is a valid positive integer
	if (scanf_s("%d", &rollNoSearchQuery) != 1 || rollNoSearchQuery <= 0) {
		printf("Invalid Roll No. Must be a positive integer.\n");
	}
	
	// initialize position of pointer with -1
	long pos = -1;

	// read the data while we are not at EOF
	while (fread(&student, sizeof(struct Student), 1, file)) {
		
		// if the current record's roll no matches the search query
		if (student.rollNo == rollNoSearchQuery) {
			
			// store the record's pointer and break
			pos = ftell(file) - sizeof(struct Student); 
			break;
		}
		
	}

	// go back to origin
	rewind(file);

	// check whether record exists
	if (pos == -1) {
		printf("Record not found!");
		return 0;
	}

	// seek the pointer of the record
	// check if successfully sought
	if (fseek(file, pos, SEEK_SET) != 0) {
		printf("Error while finding the record in the file");
		return 1;
	}
	
	// get marks from user
	printf("Enter the marks to update:");
	float marks;

	// check if marks are valid for the constraints
	if (scanf_s("%f", &marks) != 1 || marks > 100 || marks < 0) {
		printf("Invalid marks, must be a positive integer!");
		return 1;
	}
	
	
	// read the value at the sought position and store it in the student var
	fread(&student, sizeof(struct Student), 1, file);

	// reset the position to pos
	fseek(file, pos, SEEK_SET);

	// update the student's marks to user's desired marks
	student.marks = marks;

	// update it in the file by writing over the existing data
	fwrite(&student, sizeof(struct Student), 1, file);

	// go back to origin	
	rewind(file);

	printf("record updated!\n");

	// close the file pointer
	fclose(file);
	file = NULL;

	// display all the records to verify updates
	displayAllRecords();

	return 0;

}