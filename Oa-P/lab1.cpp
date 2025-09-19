#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int max = 99999;
	int arr[10];

	for (int i =0; i < 10; i++) {
		setlocale(LC_ALL, "rus");
		wcout << L"Введите элемент " << i + 1 << ":";
		cin >> arr[i];
	}

	wcout << L"Ваш массив: " << " ";
	for (int j = 0; j < 10; j++) {
		cout << arr[j] << " ";
	}

	cout << endl;
	wcout << L"Сумма элементов: " << " ";
	for (int k = 0; k < 10; k++) {
		sum += arr[k];
	}

	cout << sum << " " << endl;
	wcout << L"Минимальное число: ";
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

	wcout << L"Ваш массив в отсортированном виде: ";
	for (int end = 0; end < 10; end++) {
		cout << arr[end]<< " ";
	}
	return 0;
}