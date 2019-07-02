//============================================================================
// Name        : Reversing.cpp
// Author      : Adi Cohen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char text[] = "Hello"; //we need to reverse the string

	/*	char *pTexts = text;*/

	int length = sizeof(text) - 1; // now it's 5
	/*my way of doing that without using a pointer - using arithmetic operations*/
	cout << text << endl;
	for (int i = 0; i < length; i++) {
		if (i == length / 2) {
			break;
		}
		text[length - 1 - i] = text[length - 1 - i] + text[i];
		text[i] = text[length - 1 - i] - text[i];
		text[length - 1 - i] = text[length - 1 - i] - text[i];
	}

	cout << text << endl;
/*the instructor's way - using pointers*/
	/*char *pStart = text;
	char *pEnd = text + length - 1;
	cout << *pEnd << endl;
	while (pStart < pEnd){
		char save = *pStart;
		*pStart = *pEnd;
		*pEnd = save;

		pStart++;
		pEnd--;
	}*/
/*	cout << text << endl;*/
	return 0;
}
