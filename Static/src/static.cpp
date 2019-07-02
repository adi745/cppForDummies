//============================================================================
// Name        : static.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// normally this will be in the .h header file
class Test{
private:
	static int count; //we need to initialize it
	int id;
	char nLetter = 'a';
public:
	Test(){
		id = --count;
		nLetter++;
		name = ++nLetter;
	}
	static string name;
	static const int MAX = 99;/*it is common to declare static const as public because
 * they can't be changed*/
	int getId();
	static void showInfo();
};

// and in the .cpp source file we do the initialization:
void Test::showInfo(){
	cout << Test::count <<endl;
	cout <<"My name is: " << Test::name <<endl;
}
int Test::getId(){
	return id;
}
/*we dont need an object to access the variable*/
int Test::count = Test::MAX;
string Test::name = "adi";
int main() {

	Test::showInfo();

	Test test1;
/*using the constructor to increment the variable by 1*/
	Test test2;
	Test test3;

	test3.showInfo();
	cout << "Object 1 id: " <<test1.getId()<<endl;
	return 0;
}
