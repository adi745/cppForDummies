/*
 * matMath.h
 *
 *  Created on: Jun 14, 2019
 *      Author: adi
 */

#ifndef MATMATH_H_
#define MATMATH_H_

#include <iostream>
#include <math.h>

using namespace std;

namespace RobotMath {

	const double THRESHOLD = 0.001;

	class Matrix {
	public:
		double **matrixA;
		unsigned int rows, cols;

		//	~Matrix();
		Matrix(unsigned int rows, unsigned int cols);
		Matrix transpose();
		Matrix getCofactor(unsigned int p, unsigned int q, unsigned int n);
		Matrix adjoint(unsigned int n);
		Matrix inverse(unsigned int n);
		double determinant(unsigned int n);
	};

	class DCM :public Matrix {
	public:
		DCM(double* n, double theta, double* trans_vec);
		DCM(Matrix& matA);
		~DCM();
		//DCM matrixAdd(DCM dcmMatA, DCM dcmMatB);
		//DCM matrixSub(DCM dcmMatA, DCM dcmMatB);
	};
	class Mat : public Matrix
	{
	public:
		static Matrix matrixAdd(Matrix matA, Matrix matB);
		static Matrix matrixSub(Matrix matA, Matrix matB);
		static Matrix matrixMul(Matrix matA, Matrix matB);
		//static Matrix matrixInv(Matrix matA, unsigned int size); //size is limited to 2-4
		static bool checkOperationValid(Matrix matA, Matrix matB);
		static Matrix matrixEigenVal(Matrix matA);
		static Matrix matrixEigenVec(Matrix matA);
		static bool matCondition;
		static void freeMemory(double **pMat);
		static void printMat(Matrix matA);
	private:
	};

}

#endif /* MATMATH_H_ */
