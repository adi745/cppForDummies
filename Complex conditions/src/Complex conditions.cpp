#include <iostream>
using namespace std;

/*so far we've seen the:
 * == equality test
 * != not equals
 * < less than
 * > greater then
 * <= less than or equal to
 * >= greater than or equal to
 * && logical and operator
 * || logical or operator */

int main() {

	int value1 = 5, value2 = 3;
	if (value1 < 9) {
		cout << "condition1 is true!" << endl;
	} else {
		cout << "condition1 is false" << endl;
	}

	/*cpp reads the conditions from left to right*/
	if (value1 > 7 && value2 > 2) {
		cout << "condition2 is true!" << endl;
	} else {
		cout << "condition2 is false" << endl;
	}
	if (value1 > 7 || value2 > 2) {
		cout << "condition3 is true!" << endl;
	} else {
		cout << "condition3 is false" << endl;
	}
	/*try not to use != in the conditions, it makes the code hard to read*/
	if (value1 != 7) {
		cout << "condition4 is true!" << endl;
	} else {
		cout << "condition4 is false" << endl;
	}

	if ((value1 > 7 && value2 > 2) || value2 != 5) {
		cout << "condition5 is true!" << endl;
	} else {
		cout << "condition5 is false" << endl;
	}
	/*to make big expression conditions more readable we can use bool*/
	bool condition1 = (value1 == 7) && (value2 > 2);
	cout << condition1 << endl;
	bool condition2 = (value1>=5) && (value2 <= 5);
	cout << condition2 << endl;
	/*it's easier to understand those'*/
	if (condition1 || condition2) {
		cout << "condition6 is true!" << endl;
	} else {
		cout << "condition6 is false" << endl;
	}
	return 0;
}
