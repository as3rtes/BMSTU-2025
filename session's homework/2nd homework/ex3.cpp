#include <iostream>
using namespace std;

int main() {
	const int num = 15;
	double arr[num];
	int per;
	double dop_num = -1000000;

	for (int i = 0; i < num; i++) {
		cout << "Enter " << i + 1 << " element: ";
		cin >> arr[i];

		if (arr[i] > dop_num) {
			dop_num = arr[i];
			per = i;
		}
	}
	cout << "Before: ";
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;


	double last_el = arr[num - 1];
	arr[num - 1] = arr[per];
	arr[per] = last_el;


	for (int i = 0; i < num; i++) {
		if (arr[i] < dop_num) {
			dop_num = arr[i];
			per = i;
		}
	}

	double start = arr[0];
	arr[0] = arr[per];
	arr[per] = start;

	cout << "After: ";
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}
