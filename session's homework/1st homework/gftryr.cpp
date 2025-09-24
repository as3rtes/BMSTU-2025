#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int max = 99999;
	int arr[10];

	for (int i = 0; i < 10; i++) {
		cout << "Enter the element " << i + 1 << ":";
		cin >> arr[i];
	}

	cout << "Your array: " << " ";
	for (int j = 0; j < 10; j++) {
		cout << arr[j] << " ";
	}

	cout << endl;
	cout << "The sum of the elements: " << " ";
	for (int k = 0; k < 10; k++) {
		sum += arr[k];
	}

	cout << sum << " " << endl;
	wcout << "Minimum number: ";
	for (int n = 0; n < 10; n++) {
		if (arr[n] < max) {
			max = arr[n];
		}
	}

	cout << max << endl;

	for (int f1 = 0; f1 < 10; f1++) {
		for (int f2 = 0; f2 < 9; f2++) {
			if (arr[f2] > arr[f2 + 1]) {
				int b = arr[f2];
				arr[f2] = arr[f2 + 1];
				arr[f2 + 1] = b;
			}
		}
	}

	cout << "Your array is in sorted form: ";
	for (int end = 0; end < 10; end++) {
		cout << arr[end] << " ";
	}
	return 0;
}