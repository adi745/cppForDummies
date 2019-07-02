/*
 * Cat.h
 *
 *  Created on: May 18, 2019
 *      Author: adi
 */

#ifndef CAT_H_
#define CAT_H_

#include <iostream>
using namespace std;

class Cat{
private:
	string CatName;
	int age;
public:
	Cat(string name);
	Cat();
	Cat(string name, int age);
	string toString();
};

void speak();

#endif /* CAT_H_ */
