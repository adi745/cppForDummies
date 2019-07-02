/*class Matrix {
public:
	double **matrixA;
	Matrix() {
		this->matrixA = 0;
	}
	~Matrix(){
		cout << "Element destructed" << endl;
		delete [] matrixA;
	}
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
	double** Add(double** matrixA, double** matrixB){
	 return 0;
	 }
};*/

/*void freeMemory(Matrix *pMat) {
	cout << "Memory deallocated"<<endl;
	delete[] pMat;
}*/
/*
void freeMemory(double **pMat) {
	cout << "Memory deallocated"<<endl;
	delete[] *pMat;
}
*/
