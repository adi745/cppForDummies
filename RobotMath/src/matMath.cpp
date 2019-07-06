/*
 * matMath.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: adi
 */
#include "matMath.h"

namespace RobotMath {
#pragma region General Matrix
Matrix::Matrix(unsigned int myrows, unsigned int mycols) {
	this->matrixA = 0;
	this->rows = myrows;
	this->cols = mycols;
	matrixA = new double*[rows];
	for (unsigned int r = 0; r < rows; r++) {
		matrixA[r] = new double[cols];
		for (unsigned int c = 0; c < cols; c++) {
			/*filling with zeros*/
			matrixA[r][c] = 0.0;
		}
	}
}

Matrix Matrix::transpose() {
	Matrix matB = Matrix(this->rows, this->cols);
	for (unsigned int i = 0; i < this->rows; i++) {
		for (unsigned int j = 0; j < this->cols; j++) {
			matB.matrixA[j][i] = this->matrixA[i][j];
		}
	}
	return matB;
}

double Matrix::determinant(int n) {
	/*must be a square matrix*/
	double det = 0.0;
	Matrix submatrix(this->rows, this->cols);
	if (this->rows != this->cols) {
		return det; //not a square matrix
	} else {
		// square matrix
		if (n == 2) {
			det = this->matrixA[0][0] * this->matrixA[1][1]
					- this->matrixA[1][0] * this->matrixA[0][1];
			return det;
		} else {
			for (int x = 0; x < n; x++) {
				int subi = 0;
				for (int i = 1; i < n; i++) {
					int subj = 0;
					for (int j = 0; j < n; j++) {
						if (j == x)
							continue;
						submatrix.matrixA[subi][subj] = this->matrixA[i][j];
						subj++;
					}
					subi++;
				}
				det = det
						+ (pow(-1, x) * this->matrixA[0][x]
								* submatrix.determinant(n - 1));
			}
		}
		return det;
	}
}
#pragma endregion

#pragma region Math Operations
bool Mat::matCondition;

bool Mat::checkOperationValid(Matrix matA, Matrix matB) {
	if ((matA.rows == matB.rows) && (matA.cols == matB.cols)) {
		return true; //operations in matrices (add/subs/multiply) can be done
	} else {
		return false; //operations cannot be done
	}
}

Matrix Mat::matrixAdd(Matrix matA, Matrix matB) {
	Matrix res = Matrix(matA.rows, matA.cols);
	matCondition = checkOperationValid(matA, matB);
	if (matCondition == true) {
		for (unsigned int r = 0; r < matA.rows; r++) {
			for (unsigned int c = 0; c < matA.cols; c++) {
				res.matrixA[r][c] = matA.matrixA[r][c] + matB.matrixA[r][c];
			}
		}
		return res;
	} else {
		cout << "operation couldn't be done" << endl;
		return res;
	}
}

Matrix Mat::matrixSub(Matrix matA, Matrix matB) {

	Matrix res = Matrix(matA.rows, matA.cols);
	matCondition = checkOperationValid(matA, matB);
	if (matCondition == true) {
		for (unsigned int r = 0; r < matA.rows; r++) {
			for (unsigned int c = 0; c < matA.cols; c++) {
				res.matrixA[r][c] = matA.matrixA[r][c] - matB.matrixA[r][c];
			}
		}
		return res;
	} else {
		cout << "operation couldn't be done" << endl;
		return res;
	}
}

Matrix Mat::matrixMul(Matrix matA, Matrix matB) {
	Matrix res = Matrix(matA.rows, matB.cols);
	if (matA.cols == matB.rows) {
		for (unsigned int r = 0; r < res.rows; r++) {
			for (unsigned int c = 0; c < res.cols; c++) {
				for (unsigned i = 0; i < matA.cols; i++) {
					res.matrixA[r][c] += matA.matrixA[r][i]
							* matB.matrixA[i][c];
					if(abs(res.matrixA[r][c])<THRESHOLD){
						res.matrixA[r][c] = 0.0;
					}
				}
			}
		}
		return res;
	} else {
		cout << "operation couldn't be done" << endl;
		return res;
	}
}

//Matrix Mat::matrixInv(Matrix matA, unsigned int size) {
//	/*size is limited to 2-4*/
//	switch (size)
//	{
//	case 2:

//	case 3:
//	case 4:

//	default:
//		break;
//	}
//}
void Mat::freeMemory(double **pMat) {
	//	cout << "Memory deallocated" << endl;
	delete[] *pMat;
}

#pragma endregion

#pragma region DCM
DCM::DCM(double* n, double theta, double* trans_vec) :
		Matrix(4, 4) {
	double sT = sin(theta * M_PI / 180);
	double cT = cos(theta * M_PI / 180);
	double vT = 1.0 - cT;

	this->matrixA[0][0] = n[0] * n[0] * vT + cT;
	this->matrixA[0][1] = n[0] * n[1] * vT - n[2] * sT;
	this->matrixA[0][2] = n[0] * n[2] * vT + n[1] * sT;
	this->matrixA[0][3] = trans_vec[0];
	this->matrixA[1][0] = n[0] * n[1] * vT + n[2] * sT;
	this->matrixA[1][1] = n[1] * n[1] * vT + cT;
	this->matrixA[1][2] = n[1] * n[2] * vT - n[0] * sT;
	this->matrixA[1][3] = trans_vec[1];
	this->matrixA[2][0] = n[0] * n[2] * vT - n[1] * sT;
	this->matrixA[2][1] = n[1] * n[2] * vT + n[0] * sT;
	this->matrixA[2][2] = n[2] * n[2] * vT + cT;
	this->matrixA[2][3] = trans_vec[2];
	this->matrixA[3][0] = 0.0;
	this->matrixA[3][1] = 0.0;
	this->matrixA[3][2] = 0.0;
	this->matrixA[3][3] = 1.0;
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			if (abs(this->matrixA[i][j]) < THRESHOLD) {
				this->matrixA[i][j] = 0.0;
			}
		}
	}
}
DCM::DCM(Matrix& matA) :
		Matrix(4, 4) {
}

DCM::~DCM() {
	Mat::freeMemory(DCM::matrixA);
}

#pragma endregion

}

