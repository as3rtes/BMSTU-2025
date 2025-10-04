#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num;
	int count = 0;
	cout << "Enter array size: ";
	cin >> num;

	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cout << " Enter " << i + 1 << " element: ";
		cin >> arr[i];
		if (arr[i] > pow(2, i+1)) {
			count += 1;
		}

	}
	cout << "Count = " << count;


	return 0;
}
