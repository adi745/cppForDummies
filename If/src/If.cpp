//============================================================================
// Name        : If.cpp
// Author      : Adi Cohen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	string password = "Hey!";
	cout << "Please enter your password: " << flush;

	string input;
	cin >> input;

	cout << "'" << input << "'" << endl;

	if (input!=password){
		cout << "that's wrong" << endl;
	}
	else{
		cout << "Password accepted"<<endl;
	}

	return 0;
}
