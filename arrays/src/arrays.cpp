//============================================================================
// Name        : arrays.cpp
// Author      : Adi Cohen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	/*cout << "array of integers" << endl;
	cout << "-----------------" << endl;
	int intArr[3];

	intArr[0] = 12;
	intArr[1] = 11;
	intArr[2] = 3;
	for (int i = 0; i < 3; i++) {
		cout << "value of integer element " << i << ": " << intArr[i] << endl;
	}

	cout << "array of doubles" << endl;
	cout << "-----------------" << endl;
	double dblArr[4] = { };
	dblArr[3]=33.6;
	for (int i = 0; i < 4; i++) {
		cout << "value of double element " << i << ": " << dblArr[i] << endl;
	}


	cout<<"Array of strings"<<endl;
	string strArray[] = {"apple", "banana", "juice"};
	for (int i = 0; i < sizeof(strArray)/sizeof(*strArray); i++) {
			cout << "value of double element " << i << ": " << strArray[i] << endl;
		}
*/
	for (int i=0; i<12; i++){
		int ArrTest[i] = {};
		cout << "Hi, Elements of Array "<< i <<endl;
		for(int j=0; j<i; j++){
			ArrTest[j] = j+1;
			cout << "Element no "<< j<< ", " << ArrTest[j]<<", "<<flush;
		}
		cout <<endl;
	}
	return 0;
}
