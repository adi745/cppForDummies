/*
 * matMath.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: adi
 */
#include "matMath.h"

namespace matrixMath {
Matrix::Matrix() {
	this->matrixA = 0;
}
Matrix::~Matrix() {
//	cout << "Element destructed" << endl;
	delete[] matrixA;
}
double**Matrix::createMatrix(unsigned int myrows, unsigned int mycols) {
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
	return matrixA;
}
/*creating a general matrix with rotation angle theta around general axis n*/
double**Matrix::createMatrix(double* n, double theta, double* trans_vec) {
	double sT = sin(theta * PI / 180);
	double cT = cos(theta * PI / 180);
	double vT = 1.0 - cT;
	matrixA = Matrix::createMatrix(4, 4);
	matrixA[0][0] = n[0] * n[0] * vT + cT;
	matrixA[0][1] = n[0] * n[1] * vT - n[2] * sT;
	matrixA[0][2] = n[0] * n[2] * vT + n[1] * sT;
	matrixA[0][3] = trans_vec[0];
	matrixA[1][0] = n[0] * n[1] * vT + n[2] * sT;
	matrixA[1][1] = n[1] * n[1] * vT + cT;
	matrixA[1][2] = n[1] * n[2] * vT - n[0] * sT;
	matrixA[1][3] = trans_vec[1];
	matrixA[2][0] = n[0] * n[2] * vT - n[1] * sT;
	matrixA[2][1] = n[1] * n[2] * vT + n[0] * sT;
	matrixA[2][2] = n[2] * n[2] * vT + cT;
	matrixA[2][3] = trans_vec[2];
	matrixA[3][0] = 0.0;
	matrixA[3][1] = 0.0;
	matrixA[3][2] = 0.0;
	matrixA[3][3] = 1.0;
	for (unsigned int i=0; i< 3; i++){
		for (unsigned int j=0; j<3; j++){
			if(abs(matrixA[i][j])<THRESHOLD){
				matrixA[i][j]=0.0;
			}
		}
	}
	/*double **dcmGenMat = {n[0]*n[0]*vT+cT, n[0]*n[1]*vT-n[2]*sT, n[0]*[2]*vT+n[1]*sT, trans_vec[0];
	 n[0]*n[1]*vT+n[2]*sT, n[1]*n[1]*vT+cT, n[1]*n[2]*vT-n[0]*sT, trans_vec[1];
	 n[0]*n[2]*vT-n[1]*sT, n[1]*n[2]*vT+n[0]*sT, n[2]*n[2]*vT+cT, trans_vec[2];
	 0.0, 0.0, 0.0, 1.0};*/
	return matrixA;
}
MatrixOperations::MatrixOperations() :
		matCondition(false) {
}
bool MatrixOperations::checkOperationValid(unsigned int rowsMatA,
		unsigned int colsMatA, unsigned int rowsMatB, unsigned int colsMatB) {
	if ((rowsMatA == rowsMatB) && (colsMatA == colsMatB)) {
		return true; //operations in matrices (add/subs/multiply) can be done
	} else {
		return false; //operations cannot be done
	}
}

double** MatrixOperations::createDCM(double* n_direction, double theta,
		double* trans_vec) {
	double **dcmMat = MatrixOperations::createMatrix(n_direction, theta,
			trans_vec);
	return dcmMat;
}

double** MatrixOperations::matrixAdd(double **matA, double **matB,
		unsigned int rowsMatA, unsigned int colsMatA, unsigned int rowsMatB,
		unsigned int colsMatB) {
	matCondition = MatrixOperations::checkOperationValid(rowsMatA, colsMatA,
			rowsMatB, colsMatB);
	if (matCondition == true) {
		double **matC = MatrixOperations::createMatrix(rowsMatA, colsMatA);
		for (unsigned int r = 0; r < rowsMatA; r++) {
			for (unsigned int c = 0; c < colsMatA; c++) {
				matC[r][c] = matA[r][c] + matB[r][c];
			}
		}
		return matC;
	} else {
		return matA;
	}
}

double** MatrixOperations::matrixAdd(double **dcmMatA, double **dcmMatB) {
	/* this is for using with the DCM Matrics of order 4x4*/
	double **dcmMatC = this->matrixAdd(dcmMatA, dcmMatB, 4, 4, 4, 4);
	return dcmMatC;
}

double** MatrixOperations::matrixSub(double **matA, double **matB,
		unsigned int rowsMatA, unsigned int colsMatA, unsigned int rowsMatB,
		unsigned int colsMatB) {
	matCondition = MatrixOperations::checkOperationValid(rowsMatA, colsMatA,
			rowsMatB, colsMatB);
	if (matCondition == true) {
		double **matC = MatrixOperations::createMatrix(rowsMatA, colsMatA);
		for (unsigned int r = 0; r < rowsMatA; r++) {
			for (unsigned int c = 0; c < colsMatA; c++) {
				matC[r][c] = matA[r][c] - matB[r][c];
			}
		}
		return matC;
	} else {
		return matA;
	}
}

double** MatrixOperations::matrixSub(double **dcmMatA, double **dcmMatB) {
	/* this is for using with the DCM Matrics of order 4x4*/
	double **dcmMatC = this->matrixSub(dcmMatA, dcmMatB, 4, 4, 4, 4);
	return dcmMatC;
}

double** MatrixOperations::transpose(double **matA, unsigned int rowsMatA,
		unsigned int colsMatA) {
	unsigned int rowsMatB = colsMatA;
	unsigned int colsMatB = rowsMatA;
	double **matB = MatrixOperations::createMatrix(rowsMatB, colsMatB);
	for (unsigned int i = 0; i < rowsMatA; i++) {
		for (unsigned int j = 0; j < colsMatA; j++) {
			matB[j][i] = matA[i][j];
		}
	}
	return matB;
}
/*double** MatrixOperations::operator+(unsigned int rowsMatB, unsigned int colsMatB, double** matB){
 matCondition = MatrixOperations::checkOperationValid(this->rows, this->cols,
 rowsMatB, colsMatB);
 if (matCondition == true) {
 double **matC = MatrixOperations::createMatrix(this->rows, this->cols);
 for (unsigned int r = 0; r < this->rows; r++) {
 for (unsigned int c = 0; c < this->cols; c++) {
 matC[r][c] = this->matrixA[r][c] + matB[r][c];
 }
 }
 return matC;
 } else {
 return matrixA;
 }
 }*/

void freeMemory(double **pMat) {
//	cout << "Memory deallocated" << endl;
	delete[] *pMat;
}
void freeMemory(Matrix *pMat) {
	/*this is used if i use the new operator for creating an instance*/
//	cout << "Matrix Memory deallocated" << endl;
	delete[] pMat;
}

}

