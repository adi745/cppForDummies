//============================================================================
// Name        : classes.cpp
// Author      : Adi Cohen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cat.h"
using namespace std;

int main() {

	speak();
	Cat cat("Bob");
	Cat cat1("Joe", 11);
	Cat cat2;
	cout << "Bob memory allocation: "<< &cat << endl;
	cout << cat1.toString() << endl;
	cout << cat2.toString() << endl;
	return 0;
}
