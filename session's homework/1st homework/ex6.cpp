#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter age: ";
	cin >> age;
	if (age < 18) {
		cout << "Age < 18";

	}
	else if (age > 17 && age < 61) {
		cout << "age > 17 and age < 61";
	}
	else {
		cout << "Age > 60";
	}
	
	return 0;
}
	
