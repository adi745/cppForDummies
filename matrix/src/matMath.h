/*
 * matMath.h
 *
 *  Created on: Jun 14, 2019
 *      Author: adi
 */

#ifndef MATMATH_H_
#define MATMATH_H_

#include <iostream>
using namespace std;
#include <math.h>
#define PI 3.141592

namespace matrixMath {
class Matrix {
protected:
	double **matrixA;
	unsigned int rows, cols;
	double** createMatrix(double* n_direction, double theta, double* trans_vec);

public:
	const double THRESHOLD = 0.001;
	Matrix();
	~Matrix();
	double** createMatrix(unsigned int rows, unsigned int cols);

};

class MatrixOperations: public Matrix {
private:
	bool matCondition;
public:
	MatrixOperations();
	bool checkOperationValid(unsigned int rowsMatA, unsigned int colsMatA,
			unsigned int rowsMatB, unsigned int colsMatB);
	double** matrixAdd(double **matA, double **matB, unsigned int rowsMatA,
			unsigned int colsMatA, unsigned int rowsMatB,
			unsigned int colsMatB);
	double** matrixAdd(double **matA, double **matB);
	double** createDCM(double* n_direction, double theta, double* trans_vec);
	double** matrixSub(double **matA, double **matB, unsigned int rowsMatA,
			unsigned int colsMatA, unsigned int rowsMatB,
			unsigned int colsMatB);
	double** matrixSub(double **dcmMatA, double **dcmMatB);
	double** transpose(double **matA, unsigned int rowsMatA,
			unsigned int colsMatA);

	/*	double** operator+(unsigned int rowsMatB, unsigned int colsMatB, double** matB);*/
};

void freeMemory(double **pMat);
void freeMemory(Matrix *pMat);

}

#endif /* MATMATH_H_ */
