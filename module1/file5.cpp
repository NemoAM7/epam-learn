#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Employee {
    int empId;
    char name[50];
    float salary;
};

// Gets empId, name and salary of an employee from user and writes it into a dat file
void addEmployeeRecord() {

    // struct for new employee
    struct Employee newEmp;

    // temporary employee variables
    int empId;
    char name[50];
    float salary;

    // variable for clearing buffer
    char c;

    // clearing buffer before string input
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\n");

    // get employee name from user 
    printf("Enter Name of employee: ");

    // check if input is valid
    if (fgets(name, sizeof(newEmp.name), stdin) == NULL) {
        printf("Invalid Employee!");
        return;
    }
    // Remove newline char from fgets if present
    name[strcspn(name, "\n")] = 0;

    // get employee id from user
    printf("Enter the Employee ID: ");

    // check if the input is valid
    if (scanf_s("%d", &empId) != 1 || empId <= 0) {
        printf("Invalid ID, must be a positive integer!");
        return;
    }

    // get employee salary from user
    printf("Enter the salary: ");

    // check if the input is valid
    if (scanf_s("%f", &salary) != 1 || salary < 0) {
        printf("Invalid Salary, must be a positive number");
        return;
    }

    // copy the temporary details into the employee struct
    strcpy_s(newEmp.name, sizeof(newEmp.name), name);
    newEmp.empId = empId;
    newEmp.salary = salary;

    // variable for the file pointer
    FILE* fptr = NULL;

    // variable for error status code while opening file
    int err = fopen_s(&fptr, "employee.dat", "ab");

    // check if there was an error while opening the file
    if (err != 0) {
        printf("Error while opening the file!");
        return;
    }

    // write the employee struct into the file
    // check whether the struct was written succesfully 
    if (fwrite(&newEmp, sizeof(newEmp), 1, fptr) == 1) {
        printf("Employee added successfully\n");
    }
    else {
        printf("Error while writing to the file!");
    }

    // close the file pointer
    fclose(fptr);
    fptr = NULL;
}

// displays all the records stored in the employee dat file
void displayAllRecords() {

    // variable for the file pointer
    FILE* fptr = NULL;

    // variable for error status code while opening the file
    int err = fopen_s(&fptr, "employee.dat", "rb");

    // check if there was an error while opening the file
    if (err != 0) {
        printf("Error while opening the file (File may not exist)!\n");
        return;
    }

    // struct to read the employee file data
    struct Employee fileData;


    // loop till we reach end of file and print the data
    while (fread(&fileData, sizeof(struct Employee), 1, fptr)) {
        printf("ID\t: %d\n", fileData.empId);
        printf("Name\t: %s\n", fileData.name);
        printf("Salary\t: %.2f\n\n", fileData.salary);
    }

    //close the file pointer
    fclose(fptr);
    fptr = NULL;
}

int main() {

    // dummy data
    addEmployeeRecord();
    addEmployeeRecord();

    // display records before deletion
    displayAllRecords();


    // pointer for original file
    FILE* originalFile = NULL;
    // pointer for temporary file
    FILE* tempFile = NULL;

    // employee struct for reading data
    struct Employee emp;

    // variable for id to delete
    int empIdToDelete;
    // flag to check if record was found
    int found = 0;

    // error status code while opening original file in read binary mode
    int errOrg = fopen_s(&originalFile, "employee.dat", "rb");

    // check if there is an error while opening the file
    if (errOrg != 0) {
        printf("Error while opening employee.dat!\n");
        return 1;
    }

    // error status code while opening temp file in write binary mode
    int errTemp = fopen_s(&tempFile, "temp.dat", "wb");

    // check if there is an error while creating the temp file
    if (errTemp != 0) {
        printf("Error while creating temp.dat!\n");
        fclose(originalFile);
        return 1;
    }

    // get the empId to delete from the user
    printf("Enter the Employee ID to delete: ");

    // check if input is valid
    if (scanf_s("%d", &empIdToDelete) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // read the data while we are not at EOF
    while (fread(&emp, sizeof(struct Employee), 1, originalFile)) {

        // Conditional Logic:
        // Compare the empId of each record with the empId provided by user
        if (emp.empId == empIdToDelete) {
            found = 1;
        }
        else {
            // Write all other records to the temp.dat file
            fwrite(&emp, sizeof(struct Employee), 1, tempFile);
        }
    }

    // close both file pointers before replacing
    fclose(originalFile);
    originalFile = NULL;
    fclose(tempFile);
    tempFile = NULL;

    // File Replacement Logic
    if (found) {
        // remove the original file
        if (remove("employee.dat") != 0) {
            printf("Error deleting original file.\n");
        }
        // rename temp file to original filename
        else if (rename("temp.dat", "employee.dat") != 0) {
            printf("Error renaming temp file.\n");
        }
        else {
            printf("Employee record deleted successfully.\n");
        }
    }
    else {
        // if record not found, delete the temp file
        remove("temp.dat");
        printf("Employee record not found.\n");
    }

    // display all the records to verify deletion
    displayAllRecords();

    return 0;
}