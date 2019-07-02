#include <iostream>
using namespace std;

int main() {

	bool bValue = true;

	cout << bValue << endl;

	bValue = false;

	cout << bValue << endl;

	char cValue = 125; //output the character A - using ASCII Table

	cout << cValue << endl;
	cout << (int)cValue << endl; //output the real value
	cout << "The size in bytes of char: " << sizeof(char) << endl;

	cValue = 'G';

	cout << cValue << endl; //output the symbol G

	wchar_t wValue = 275; //size is bigger than char so we can store more values in it
	cout << (char)wValue << endl; //output the wchar_t value
	cout << "The size in bytes of wchar: " << sizeof(wchar_t) << endl;

	return 0;
}
