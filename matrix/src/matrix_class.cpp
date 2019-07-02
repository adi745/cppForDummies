//============================================================================
// Name        : MatrixMath.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "matMath.h"

using namespace matrixMath;

int main() {
	unsigned int rows = 4;
	unsigned int cols = 5;
	MatrixOperations *pMat = new MatrixOperations();
	double **A = pMat->createMatrix(rows, cols);
	A[2][0] = 12.5;
	A[3][2] = 3.5;
	A[0][3] = 0.5;
	double **B = pMat->createMatrix(rows, cols);
		B[1][2] = 12.5;
		B[2][3] = 13.5;
		B[3][0] = -1.5;
	double **C = pMat->matrixSub(A, B, rows, cols, rows, cols);
	cout << "C Matrix:" <<endl;
	for (unsigned int r = 0; r < rows; r++) {
		for (unsigned int c = 0; c < cols; c++) {
			cout << C[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;
	/*createMatrix(rows, cols);*/
	double n[] = { 0.0, 0.0, 1.0 };
	double trans[] = { 1.0, 0.0, 0.0 };
	double **D = pMat->createDCM(n, PI / 2, trans);
	n[2] = -1.0;
	double **E = pMat->createDCM(n, PI / 4, trans);
	cout << "D DCM Matrix:" <<endl;
	for (unsigned int r = 0; r < 4; r++) {
			for (unsigned int c = 0; c < 4; c++) {
				cout << D[r][c] << ", " << flush;
			}
			cout << endl;
		}
	cout << endl;
	cout << "E DCM Matrix:" <<endl;
	for (unsigned int r = 0; r < 4; r++) {
		for (unsigned int c = 0; c < 4; c++) {
			cout << E[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;
	/*bool checkMatOper = pMat->checkOperationValid(rows, cols, rows, cols);
	cout << checkMatOper << endl;*/
	/*double **F = pMat->matrixSub(B, C);*/
	double **F = pMat->transpose(E, 4, 4);
	cout << "F DCM Matrix:" <<endl;
	for (unsigned int r = 0; r < 4; r++) {
		for (unsigned int c = 0; c < 4; c++) {
			cout << F[r][c] << ", " << flush;
		}
		cout << endl;
	}
	freeMemory(A);freeMemory(B);
	freeMemory(C);freeMemory(D);
	freeMemory(E); freeMemory(F);
	freeMemory(pMat);
	return 0;
}
