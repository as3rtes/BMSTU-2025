#include <iostream>
using namespace std;

int main() {
	int num;
	cout << "Enter num: ";
	cin >> num;
	if (num % 5 == 0 && num % 3 == 0) {
		cout << "Del 3 and 5";
	}
	else {
		if (num % 5 == 0) {
			cout << "Del 5";
		}
		else if (num % 3 == 0) {
			cout << "Del 3";
		}
		else {
			cout << "error num";
		}

		return 0;
	}
}
	
