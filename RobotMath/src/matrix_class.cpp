//============================================================================
// Name        : MatrixMath.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "matMath.h"
#include <typeinfo>
using namespace RobotMath;

int main() {

	double n[] = { 0.0, 0.0, 1.0 };
	double trans[] = { 1.0, 0.0, 0.0 };
	/*	cout << M_PI <<endl;*/
	DCM aMat = DCM(n, 45, trans);
	trans[0] = 1.5;
	trans[1] = 1.5;
	DCM bMat = DCM(n, 0, trans);
	bMat.matrixA[0][1] = 2;
	bMat.matrixA[0][2] = 3;
	bMat.matrixA[0][3] = 4;
	bMat.matrixA[1][0] = 2;
	bMat.matrixA[1][2] = 3;
	bMat.matrixA[1][3] = 4;
	for (unsigned int r = 0; r < aMat.rows; r++) {
		for (unsigned int c = 0; c < aMat.cols; c++) {
			cout << aMat.matrixA[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;

	for (unsigned int r = 0; r < bMat.rows; r++) {
		for (unsigned int c = 0; c < bMat.cols; c++) {
			cout << bMat.matrixA[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;

	Matrix cMat = Mat::matrixMul(aMat, bMat);

	/*	DCM& dMat = static_cast<DCM&>(cMat);*/
	DCM dMat = DCM(cMat);

	string s = typeid(dMat).name();
	cout << s << endl;

	for (unsigned int r = 0; r < dMat.rows; r++) {
		for (unsigned int c = 0; c < dMat.cols; c++) {
			cout << dMat.matrixA[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;

	cMat.matrixA[2][2] = 12.5;
	cMat.matrixA[1][4] = -1.55;
	cMat.matrixA[3][0] = 3.52;

	for (unsigned int r = 0; r < cMat.rows; r++) {
		for (unsigned int c = 0; c < cMat.cols; c++) {
			cout << cMat.matrixA[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;
	Matrix eMat = bMat.adjoint(4);
	for (unsigned int r = 0; r < eMat.rows; r++) {
		for (unsigned int c = 0; c < eMat.cols; c++) {
			cout << eMat.matrixA[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;

	double detbMat = bMat.determinant(bMat.rows);
	cout << detbMat << endl;

	Matrix fMat = bMat.inverse(4);
	cout << "fMat: " << endl;
	for (unsigned int r = 0; r < fMat.rows; r++) {
		for (unsigned int c = 0; c < fMat.cols; c++) {
			cout << fMat.matrixA[r][c] << ", " << flush;
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
