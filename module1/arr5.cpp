#include<iostream>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

// input a matrix
void inputMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "Enter element at Row " << i << " and Column " << j << " : ";
			cin >> matrix[i][j];
		}
	}
}

// private function to add two matrices
void _addMatrices(int rows, int cols, int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int parity) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result[i][j] = mat1[i][j] + mat2[i][j] * parity;
		}
	}
}

// add two matrices
void addMatrices(int rows, int cols, int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
	_addMatrices(rows, cols, mat1, mat2, result, 1);
}

// subtract two matrices
void subtractMatrices(int rows, int cols, int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
	_addMatrices(rows, cols, mat1, mat2, result, -1);
}

// multiply two matrices
void multiplyMatrices(int r1, int c1, int r2, int c2, int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
			result[i][j] = 0;
			for (int k = 0; k < c1; k++) {
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

// transpose of a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS], int result[MAX_COLS][MAX_ROWS]) {
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			result[i][j] = matrix[j][i];
		}
	}
}

// print a matrix
void printMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
	for (int i = 0; i < rows; i++) {
		cout << "[\t";
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] <<  ",\t";
		}
		cout << "]\n";
	}
}

int main() {
	int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], mat3[MAX_ROWS][MAX_COLS], choice;
	int row1, row2, col1, col2;
	cout << "Which matrix operation would you like to perform?\n[1] Add\n[2] Subtract\n[3] Multiply\n[4] Transpose\n Press any key to exit!\n";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Enter the number of rows of matrices : ";
		cin >> row1;
		cout << "Enter the number of columns of matrices : ";
		cin >> col1;

		cout << "Enter values for matrix 1" << endl;
		inputMatrix(row1, col1, mat1);

		cout << "Enter values for matrix 2" << endl;
		inputMatrix(row1, col1, mat2);

		addMatrices(row1, col1, mat1, mat2, mat3);

		printMatrix(row1, col1, mat1);
		cout << "+" << endl;
		printMatrix(row1, col1, mat2);
		cout << "=" << endl;
		printMatrix(row1, col1, mat3);
		break;


	case 2:
		cout << "Enter the number of rows of matrices : ";
		cin >> row1;
		cout << "Enter the number of columns of matrices : ";
		cin >> col1;

		cout << "Enter values for matrix 1" << endl;
		inputMatrix(row1, col1, mat1);

		cout << "Enter values for matrix 2" << endl;
		inputMatrix(row1, col1, mat2);

		subtractMatrices(row1, col1, mat1, mat2, mat3);

		printMatrix(row1, col1, mat1);
		cout << "-" << endl;
		printMatrix(row1, col1, mat2);
		cout << "=" << endl;
		printMatrix(row1, col1, mat3);
		break;

	case 3:
		cout << "Enter the number of rows of matrix 1 : ";
		cin >> row1;
		cout << "Enter the number of columns of matrix 1 : ";
		cin >> col1;

		cout << "Enter values for matrix 1" << endl;
		inputMatrix(row1, col1, mat1);

		cout << "Enter the number of rows of matrix 2 : ";
		cin >> row2;
		cout << "Enter the number of columns of matrix 2 : ";
		cin >> col2;

		cout << "Enter values for matrix 2" << endl;
		inputMatrix(row1, col1, mat2);
		
		if (col1 != row2) {
			cout << "Column of first row should be equal to row of second row!" << endl;
			return 1;
		}

		multiplyMatrices(row1, col1, row2, col2, mat1, mat2, mat3);
		
		printMatrix(row1, col1, mat1);
		cout << "*" << endl;
		printMatrix(row2, col2, mat2);
		cout << "=" << endl;
		printMatrix(row1, col2, mat3);
		break;
	case 4:
		cout << "Enter the number of rows of matrix : ";
		cin >> row1;
		cout << "Enter the number of columns of matrix : ";
		cin >> col1;

		cout << "Enter values for matrix 1" << endl;
		inputMatrix(row1, col1, mat1);

		transposeMatrix(row1, col1, mat1, mat3);

		printMatrix(row1, col1, mat1);
		cout << "T\n=" << endl;
		printMatrix(col1, row1, mat3);
		break;
	case 5:
		cout << "exiting..." << endl;
		return 0;

	}
	return 0;
}