#include<stdio.h>

/*
 * File : DisplayStudentInfo.c
 * Author : Ayaan Mandal
 * Created on : 16th January 2026
 * Description : This file contains a simple C program that displays student infromation from user input.
 */

int main() {
	// Declare student names
	char student_1_name[20], student_2_name[20], student_3_name[20];

	// Declare student ages
	int student_1_age, student_2_age, student_3_age;

	// Declare student GPAs (Grade Point Average out of 10.0)
	float student_1_gpa, student_2_gpa, student_3_gpa;

	// Take input for student 1 and check for input errors
	printf("Enter name of Student 1: ");
	if (scanf("%s", student_1_name) != 1) {
		printf("Input error in student name!\n");
		return 1;
	}

	printf("Enter age of Student 1 in years: ");
	if (scanf("%d", &student_1_age) != 1) {
		printf("Input error in student age!\n");
		return 1;
	}

	printf("Enter GPA (out of 10.0) of Student 1: ");
	if (scanf("%f", &student_1_gpa) != 1) {
		printf("Input error in student GPA!\n");
		return 1;
	}

	//Take input for student 2 and check for input errors
	printf("Enter name of Student 2: ");
	if (scanf("%s", student_2_name) != 1) {
		printf("Input error in student name!\n");
		return 1;
	}

	printf("Enter age of Student 2 in years: ");
	if (scanf("%d", &student_2_age) != 1) {
		printf("Input error in student age!\n");
		return 1;
	}

	printf("Enter GPA (out of 10.0) of Student 2: ");
	if (scanf("%f", &student_2_gpa) != 1) {
		printf("Input error in student GPA!\n");
		return 1;
	}

	//Take input for student 3 and check for input errors	
	printf("Enter name of Student 3: ");
	if (scanf("%s", student_3_name) != 1) {
		printf("Input error in student name!\n");
		return 1;
	}
	printf("Enter age of Student 3 in years: ");
	if (scanf("%d", &student_3_age) != 1) {
		printf("Input error in student age!\n");
		return 1;
	}
	printf("Enter GPA (out of 10.0) of Student 3: ");
	if (scanf("%f", &student_3_gpa) != 1) {
		printf("Input error in student GPA!\n");
		return 1;
	}

  //Print Student Information in tabular format
  printf("\n--- Student Information ---\n");
  printf("|----------------------|-----|---------|\n");
  printf("|         Name         | Age |   GPA   |\n");
  printf("|----------------------|-----|---------|\n");
  
  printf("| %-20s | %3d | %7.2f |\n", student_1_name, student_1_age, student_1_gpa); // format spaces, allignment, datatype and precision of values.
  printf("|----------------------|-----|---------|\n");
  
  printf("| %-20s | %3d | %7.2f |\n", student_2_name, student_2_age, student_2_gpa);
  printf("|----------------------|-----|---------|\n");
  
  printf("| %-20s | %3d | %7.2f |\n", student_3_name, student_3_age, student_3_gpa);
  printf("|----------------------|-----|---------|\n");

	return 0;
}