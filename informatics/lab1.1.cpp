#include <iostream>
using namespace std;

int main() {
	int count;
	setlocale(LC_ALL, "rus");
	wcout; L"������� ���������� �������: ";
	cin >> count;

	for (int i = 0; i < count + 1; i++) {
		cout << "-" << i * 10 << endl;
	}

	return 0;
}