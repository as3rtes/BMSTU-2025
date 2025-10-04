#include <iostream>
using namespace std;

int main() {
	int num;
	int mx = 0;
	int count = 0;
	cout << "Enter array size: ";
	cin >> num;

	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cout << " Enter " << i + 1 << " element: ";
		cin >> arr[i];

		if ((arr[i] % 2 != 0) && (arr[i] > mx)) {
			mx = arr[i];
		}
		else {
			count += 1;
		}
		
	}
	cout << "Maximal odd number: " << mx << endl;
	cout << "Count even numbers: " << count;

	return 0;
}
