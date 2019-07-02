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

namespace matrixMath {
double **matrixA;
double** createMatrix(unsigned int rows, unsigned int cols) {
	matrixA = new double*[rows];
	for (unsigned int r = 0; r < rows; r++) {
		matrixA[r] = new double[cols];

		for (unsigned int c = 0; c < cols; c++) {
			// fill in some initial values
			// (filling in zeros would be more logic, but this is just for the example)
			matrixA[r][c] = 0.0;
		}
	}
	return matrixA;
}
void freeMemory(double **pMat) {
	cout << "Memory deallocated" << endl;
	delete[] *pMat;
}

}

#endif /* MATMATH_H_ */
