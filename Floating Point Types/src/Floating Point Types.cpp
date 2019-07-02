#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	float fValue = 76.4; //6 significant digits

	cout << fValue << endl;

	cout << fixed << fValue << endl;
	cout << scientific << fValue << endl;
	/*cout has a specific number of digits it can output by default*/
	cout <<"size of the var in bytes: "<< sizeof(fValue)<< endl;

	double dValue = 76.4; //15 significant digits

	cout << setprecision(20) << fixed << dValue << endl;
	cout <<"size of the var in bytes: "<< sizeof(dValue)<< endl;
	/*takes 8 bytes to represent one number*/

	long double ldValue = 12.51245552365; //for even better precision

	cout << setprecision(20) << fixed << ldValue << endl;
	cout <<"size of the var in bytes: "<< sizeof(ldValue)<< endl;
	/*takes 16 bytes to represent one number*/


	return 0;
}
