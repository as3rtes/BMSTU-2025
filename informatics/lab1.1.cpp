#include <iostream>
using namespace std;

int main() {
	int count;
	cout; L"Enter the number of plates: ";
	cin >> count;

	for (int i = 0; i < count + 1; i++) {
		cout << "-" << i * 10 << endl;
	}

	return 0;
}

