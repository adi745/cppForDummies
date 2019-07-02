//============================================================================
// Name        : inheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
private:
	int age;
public:
	Animal() :
			age(0) {
		cout << "Animal no argument constructor was called." << endl;
	}
	Animal(int age) :
			age(age) {
		cout << "Animal no argument constructor was called." << endl;
	}
	void speak() {
		cout << "grrr..." << endl;
	}
	void info() {
		cout << "My age is: " << age << endl;
	}
};

class Cat: public Animal {
public:
	Cat() {
			Cat::speak();
	}
	Cat(int age):Animal(age) {
		Cat::speak();
	}
	void jump() {
		cout << "jumping" << endl;
	}
};

class Tiger: public Cat {
public:
	Tiger(int age):Cat(age) {
		cout << "Tiger no argument constructor was called." << endl;
	}
	void attackAntilope() {
		cout << "Attacking!" << endl;
	}
};

class Frog: public Animal {
private:
	string name;
	string getName() {
		return name;
	}
public:
	Frog(string myName) :
			name(myName) {
	}
	void info() {
		cout << "My name is: " << getName() << endl;
	}
};

int main() {

	Animal animal(11);
	animal.info();

	Tiger tiger(31);
	tiger.info();
	/*
	 Tiger tiger;
	 tiger.jump();
	 tiger.attackAntilope();
	 Frog frog("Freddy");
	 frog.info();
	 */
	return 0;
}
