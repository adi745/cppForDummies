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
	Mat::printMat(aMat);

	Mat::printMat(bMat);

	Matrix cMat = Mat::matrixMul(aMat, bMat);

	/*	DCM& dMat = static_cast<DCM&>(cMat);*/
	DCM dMat = DCM(cMat);

	string s = typeid(dMat).name();
	cout << s << endl;
	Mat::printMat(dMat);

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
	Mat::printMat(eMat);

	double detbMat = bMat.determinant(bMat.rows);
	cout << detbMat << endl;

	Matrix fMat = bMat.inverse(4);
	cout << "fMat: " << endl;
	Mat::printMat(fMat);

	trans[0] = 0;
	trans[1] = 0;
	DCM gMat = DCM(n, 0, trans);
	gMat.matrixA[0][0] = 2.0; gMat.matrixA[1][1] = 3.0;
	cout << "gMat: " << endl;
	Mat::printMat(gMat);
	cout << "Val:" << endl;
	Matrix Val = Mat::matrixEigenVal(gMat);
	Mat::printMat(Val);
	Matrix Vec = Mat::matrixEigenVec(gMat);
	Mat::printMat(Vec);
	return 0;
}
