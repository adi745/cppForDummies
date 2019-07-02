#include <iostream>
/*the angled brackets refer to stndard location
 * which the compiler knows about an automatically look at*/
#include "util.h"
/*this "" refers to another location within the project*/
/*the compiler see instead of this file
 * an actual decleration of the functions*/

using namespace std;

int main() {

	doSomething();
	doSomething();

	return 0;
}


void doSomething(){
	cout << "Hello"<< endl;
}
