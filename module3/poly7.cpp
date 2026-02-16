#include<iostream>
#include<vector>
using namespace std;

class Matrix {
protected:
    vector<vector<double>> matrix;
	int rows;
	int cols;

public:
	Matrix(): rows(0), cols(0) {}
	Matrix(int rows, int cols) : rows(rows), cols(cols), matrix(rows, vector<double>(cols, 0)) {}

	virtual void display() const {
		cout << "Matrix( shape=(" << rows << "," << cols << "), data=\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << ")\n";
	}

	Matrix operator+(Matrix other) {
		if (other.rows != rows || other.cols != cols) {
			cout << "Matrix sizes are not same, cannot add them!" << endl;
			return *this;
		}

		Matrix new_matrix(rows, cols);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				new_matrix.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
			}
		}

		return new_matrix;
	}

	virtual void setValue(int row, int col, int value) {
		if (row < 0 or row >= rows or col < 0 or col >= cols) {
			cout << "Ensure the index is a valid index for matrix of size (" << rows << "," << cols << ")." << endl;
			return;
		}
		matrix[row][col] = value;
	}

	virtual void setValue(int row, int col, double value) {
		if (row < 0 or row >= rows or col < 0 or col >= cols) {
			cout << "Ensure the index is a valid index for matrix of size (" << rows << "," << cols << ")." << endl;
			return;
		}
		matrix[row][col] = value;
	}
};

class SquareMatrix : public Matrix {
public:
	SquareMatrix(int size): Matrix(size, size) {}

	void display() const override {
		cout << "SquareMatrix( shape=" << rows << ", data=\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << ")\n";
	}
};

class IdentityMatrix : public SquareMatrix {
public:
	IdentityMatrix(int size) : SquareMatrix(size) {
		for (int i = 0; i < size; i++) {
			matrix[i][i] = 1;
		}
	}

	void display() const override {
		cout << "IdentityMatrix( shape=" << rows << ", data=\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << ")\n";
	}

	void setValue(int row, int col, int value) {
		cout << "Identity matrix cannot be modified!" << endl;
	}
	void setValue(int row, int col, double value) {
		cout << "Identity matrix cannot be modified!" << endl;
	}
};

int main() {
	Matrix mat1(2, 3), mat2(2, 3), mat3(2, 2), mat4;
	SquareMatrix sq_mat1(2);

	mat3.display();

	mat1.setValue(0, 2, 10);
	mat1.setValue(1, 2, 120.2);
	mat1.setValue(1, 0, 30);

	mat2.setValue(4, 2, 200);
	mat2.setValue(1, 2, -1.8);
	mat2.setValue(1, 1, 3.1);

	mat1.display();
	mat2.display();

	mat4 = mat1 + mat2;
	mat4.display();

	mat4 = mat1 + mat3;

	mat3.setValue(1, 1, 20);
	sq_mat1.setValue(1, 1, 30);

	mat4 = mat3 + sq_mat1;

	sq_mat1.display();
	mat4.display();

	IdentityMatrix i_mat1(4);

	i_mat1.display();

	i_mat1.setValue(3, 2, 10);

	vector<Matrix*> matrices;
	matrices.push_back(&mat1);
	matrices.push_back(&i_mat1);
	matrices.push_back(&sq_mat1);

	for (Matrix* mat : matrices) {
		mat->display();
	}

	return 0;
}