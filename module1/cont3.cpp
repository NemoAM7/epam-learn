#include <stdio.h>

int main() {

    // flag to continue processing students
    char process_students; 
    
    // student unique id, and running data for student assignments and grades
    short student_id, num_assignments, grade, total_grades, valid_assignments_count, average_grade;

    printf("Welcome to the Student Grade Analyzer!\n");

    // main loop to process multiple students
    do {

        // reset for each student
        total_grades = 0;
        valid_assignments_count = 0;

        // loop to get valid student id
        do {
            // get student id
            printf("Enter Student ID (101-999): ");
            scanf("%hd", &student_id);

            // validate student id
            if (student_id < 101 || student_id > 999) { 
                printf("Invalid Student ID. Must be between 101 and 999. Please re-enter.\n");
            }

        } while (student_id < 101 || student_id > 999);

        // get number of assignments of each student
        printf("How many assignments does Student %hd have: ", student_id);
        scanf("%hd", &num_assignments);
        
        // loop to get each assignment grade
        for (int assignment = 1; assignment <= num_assignments; assignment++) {

            // get grade for each assignment
            printf("Enter grade for Assignment #%d (0-100): ", assignment);
            scanf("%hd", &grade);

            // validate grade
            if (grade < 0 || grade > 100) {
                printf("Invalid grade. Must be between 0 and 100. Skipping this assignment.\n");
                continue;
            }

            // accumulate the running total and count of valid grades
            valid_assignments_count++;
            total_grades += grade;
        }

        // calculate and display average grade and performance message
        if (valid_assignments_count == 0) {
            printf("No valid grades entered for Student %hd.\n", student_id);
        }
        else {
            average_grade = total_grades / valid_assignments_count;
            printf("Student %hd - Average Grade %hd.\n", student_id, average_grade);
            
            if (average_grade >= 90) {
                printf("Excellent!\n");
            }
            else if (average_grade >= 70) {
                printf("Good job!\n");
            }
            else if (average_grade >= 50) {
                printf("Needs Improvement.\n");
            }
            else {
                printf("At risk.\n");
            }
        }

        // get user input to process another student or exit
        printf("Process another student? (Y/N): ");
        scanf(" %c", &process_students); // Note the space before %c to catch the newline character

    } while (process_students != 'N' && process_students != 'n');

    printf("Exiting Grade Analyzer. Goodbye!\n");
    return 0;
}