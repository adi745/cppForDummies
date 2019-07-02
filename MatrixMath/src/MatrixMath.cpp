//============================================================================
// Name        : MatrixMath.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "matMath.h"
using namespace std;

int main() {
	unsigned int rows = 4;
	unsigned int cols = 5;
	/*Matrix *pMatA = new Matrix();*/
	double **a = matrixMath::createMatrix(rows, cols);
	//	a[2][0] = 12.5; a[3][2] = 3.5; a[0][3] = 0.5;
	for (unsigned int r = 0; r < rows; r++) {
		for (unsigned int c = 0; c < cols; c++) {
			cout << a[r][c] << ", " << flush;
		}
		cout << endl;
	}
	matrixMath::freeMemory(a);
	//freeMemory (pMatA);
	return 0;
}

