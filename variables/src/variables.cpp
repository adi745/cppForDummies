//============================================================================
// Name        : variables.cpp
// Author      : Adi Cohen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int numberCats = 5; //allocated place to store an int value
	//using camel case - each subsequent word we use the capital case to indicate it
	int numberDogs = 7;
	/*	int number_cats = 5; //using underscore here*/

/*	int numberAnimals = numberCats + numberDogs;*/
	cout << "Number of cats: " << numberCats << endl;
	cout << "Number of dogs: " << numberDogs << endl;

	cout << "Total number of animals: " << numberCats + numberDogs << endl;

	cout << "New dog acquired!" << endl;
	numberDogs += 1;
	cout << "New number of dogs: " << numberDogs << endl;
	cout << "Two cats has left!" << endl;
	numberCats -= 2;
	cout << "New number of cats: " << numberCats << endl;
	cout << "Total number of animals: " << numberCats + numberDogs << endl;
	return 0;
}
