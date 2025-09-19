#include <iostream>
using namespace std;

int main() {
	double sol;
	setlocale(LC_ALL, "rus");
	wcout << L"¬ведите заработную плату:";
	cin >> sol;

	if (sol < 50001) {
		cout << sol / 100 * 13 << endl;
	}

	if (sol > 50000 && sol < 100001) {
		cout << sol / 100 * 20 << endl;
	}

	if (sol > 100000) {
		cout << sol / 100 * 25 << endl;
	}

	return 0;
}