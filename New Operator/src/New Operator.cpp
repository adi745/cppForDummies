//============================================================================
// Name        : New.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <tuple>
using namespace std;

class Animal {
private:
	string name;
	int age;
public:
	Animal() {
		name = "Tedd";
		age = 11;
		cout << "New animal created!" << endl;
	}
	Animal(const Animal &other) :
			name(other.name), age(other.age) {
		cout << "Animal " << name << " created by copy constructor" << endl;
	}
	~Animal() {
		cout << "Animal " << name << " destructed" << endl;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}

	void speak() {
		cout << "My name is: " << name << endl;
		cout << "My age is: " << name << endl;
	}
};

Animal *createAnimal(string name) {
	Animal *pAnimal = new Animal; //creating a temp object
	/*the compiler does an optimization by understanding that we search only for one object*/
	pAnimal->setName(name);
	return pAnimal;
}

tuple<Animal, Animal> create2Animals(string name, string name2) {
	Animal pAnimal, p2Animal;
	pAnimal.setName(name);
	p2Animal.setName(name2);
	return std::make_tuple(pAnimal, p2Animal);
}

Animal *createNewAnimal(string name, int age) {
	Animal *pTempAnimal = createAnimal(name);
	pTempAnimal->setName(name);
	pTempAnimal->setAge(age);
	return pTempAnimal;
}

int main() {
	Animal *pfrog = createAnimal("Todd");
	pfrog->speak();
	delete pfrog; // because we used new so the memory is allocated
	Animal pCat, pDog;
	std::tie(pCat, pDog) = create2Animals("Jerr", "Tom");
	Animal *pCamel = createNewAnimal("Brad", 21);
	pCamel->speak();
	delete pCamel; // because we used new so the memory is allocated
	return 0;
}
