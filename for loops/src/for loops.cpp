#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 4; i++) {
		if (i == 2)
			continue;
		cout << "Hello:\t" << i << endl;
	}
	return 0;
}
