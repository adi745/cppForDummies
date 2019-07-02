#include <iostream>
using namespace std;

int main() {

	string text1 = "Hello";
	string text2 = "Fred";
	string text3 = " ";
	string text4 = text1+" "+text2+"!!";
	/*string is technically a class and value is technically an object*/

	cout << text2 << text3 << text1 << endl;
	cout << text1+text3+text2 << endl;
	cout << text4 <<endl;

	cout<<"Please enter your name: "<<flush;
	string input;
	cin >> input; //using the extraction operator >> to insert new data from the user
	cout<<"You entered: "<<input<<endl;

	cout<<"Please enter a number: "<<flush;
	int value;
	cin>>value;
	cout<<"You entered: "<<value<<endl;

	return 0;
}
