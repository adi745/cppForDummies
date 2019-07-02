/*
 * Cat.cpp
 *
 *  Created on: May 18, 2019
 *      Author: adi
 */
#include "Cat.h"
#include <sstream>
/*#include <iostream>

 using namespace std;*/

Cat::Cat(string name) :
		CatName(name) {
	cout << "Hi" << endl;
}
Cat::Cat() {
	this->CatName = "Leo";
	this->age = 5;
	cout << "Meouu" << endl;
	cout <<"Leo memory allocation: "<< this << endl;

}
Cat::Cat(string name, int age) {
	this->CatName = name;
	this->age = age;
	cout << name << " memory allocation: "<< this << endl;

}

string Cat::toString() {
	stringstream ss;
	ss << "Age: ";
	ss << age;
	ss << "; Name: ";
	ss << CatName;
	return ss.str();
}
void speak() {
	cout << "Miauuu" << endl;
}

