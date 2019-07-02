//============================================================================
// Name        : Arrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

string numbers[]={"one", "two", "three"};


void show1(string texts[],const int nElements){
	for (int i=0; i<nElements;i++){
		cout << texts[i]<< ", "<< flush;
	}
	cout << endl;
}

/*it's exactly the same like show1*/
void show2(string *texts,const int nElements){
	for (int i=0; i<nElements;i++){
		cout << texts[i]<< ", "<< flush;
	}
	cout << endl;
}
/*if i want to determine the array size i need to pass it as a pointer
 * using references*/
void show3(string (&texts)[4]){
	for (int i=0; i<sizeof(texts)/sizeof(texts[0]);i++){
		cout << texts[i]<< ", "<< flush;
	}
	cout << endl;
}

string *getArray(){
	//Don't return pointers to local variables, they don't exist:
	//string texts[]={"carrot", "banana", "apple"};
	return numbers;
}

int main() {
	string texts[] = {"orange", "carrot", "banana", "watermelon"};
	int nElements = sizeof(texts)/sizeof(texts[0]);
	// inside the function it returns the size of pointer
	cout << nElements << endl;
	show1(texts, nElements);
	show2(texts, nElements);
	show3(texts);
	string *pNums = getArray();
	delete [] pNums;
	/*for (int i=0; i<sizeof(Nums)/sizeof(string); i++){
		cout << Nums[i] << endl;
	}*/
	return 0;
}
