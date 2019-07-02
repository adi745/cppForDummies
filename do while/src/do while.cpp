#include <iostream>
using namespace std;

int main() {

	const string Msg = "Please Type a Key, Q or q is for exiting: ";
	/*when defining the string as const it can't be changed*/
	char input;
	do{
		cout << Msg << flush;
		cin>>input;
		/*continue asking for input till we press q or Q*/
		if(input=='q' || input =='Q'){
			cout <<"exiting the program!"<<endl;
			break;
		}
	}
	while(true);

	return 0;
}
