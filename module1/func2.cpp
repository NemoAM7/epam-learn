#include<iostream>
using namespace std;

// Function to calculate average marks of a student
float calculateAverage(int marks[], int numSubjects) {
	int totalScore = 0;

	for(int i = 0; i < numSubjects; i++){
		totalScore += marks[i];
	}

	return (float)totalScore / numSubjects;
}

// Function to determine grade based on average marks of a student
char determineGrade(float average) {
	if(average >= 90) {
		return 'A';
	} else if(average >= 80) {
		return 'B';
	} else if(average >= 70) {
		return 'C';
	} else if (average >= 60) {
        return 'D';
    } else {
		return 'F';
	}
}

// Function to display marks, average and grade of a student
void displayArray(int marks[], int numSubjects, char grade, float average) {
	cout << "Student Report\n";
	for (int i = 0; i < numSubjects; i++) {
		cout << "Subject " << (i + 1) << ": " << marks[i] << endl;
	}
	cout << "Average Marks: " << average << endl;
	cout << "Grade: " << grade << endl;

}

int main() {

	// Input number of subjects
	int numSubjects;
	cout << "Enter number of subjects: ";
	cin >> numSubjects;

	// Variable declarations
	int *marks = new int[numSubjects];
	char grade;
	float average;

	// Input marks for each subject
	for (int i = 0; i < numSubjects; i++) {
		cout << "Enter marks for subject " << (i + 1) << ": ";
		cin >> marks[i];
	}

	// Calculate average and determine grade
	average = calculateAverage(marks, numSubjects);
	grade = determineGrade(average);
	displayArray(marks, numSubjects, grade, average);

}