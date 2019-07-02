#include <iostream>
#include <limits.h>

using namespace std;

int main() {

	int IValue = 5686151345656;
	cout << "Value of int: " << IValue << endl;

	cout << "Max int value: " << INT_MAX << endl;
	cout << "Min int value: " << INT_MIN << endl;

	cout << "Size of int in bytes: " << sizeof(int) << endl;

	short int sValue = 1255454;

	cout << "Value of short int: " << sValue << endl;

	cout << "Max short int value: " << SHRT_MAX << endl;
	cout << "Min short int value: " << SHRT_MIN << endl;

	cout << "Size of short int in bytes: " << sizeof(short int) << endl;

	long int lValue = 1213215225;
	cout << "Value of long int: " << lValue << endl;

	cout << "Max long int value: " << LONG_MAX << endl;
	cout << "Min long int value: " << LONG_MIN << endl;

	cout << "Size of long int in bytes: " << sizeof(long int) << endl;

	unsigned int uValue = 1213215225;
	cout << "Value of unsigned int: " << uValue << endl;

	cout << "Max unsigned int value: " << UINT_MAX << endl;

	cout << "Size of long int in bytes: " << sizeof(unsigned int) << endl;

	return 0;
}
