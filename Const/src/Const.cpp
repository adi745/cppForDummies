//============================================================================
// Name        : Const.cpp
// Author      : Adi Cohen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
private:
	string name;
public:
	Animal():name("Fred") {};
	void SetName(string newName){this->name = newName;};
	void speak()  {
		cout << "My name is: " << name << endl; name= "jdjdj";
	}
};

int main() {

	const double PI = 3.141592;
	Animal animal;
	animal.speak();
	animal.SetName("John");
	animal.speak();
	return 0;
}
