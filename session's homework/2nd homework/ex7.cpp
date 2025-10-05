#include <iostream>
using namespace std;

int main() {
    const int size = 15;
    int arr[size];
    int min_index = 0, max_index = 0;
    int mx = -1000000;
    int mn = 1000000;

    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];

        if (arr[i] > mx) {
            mx = arr[i];
            max_index = i;
        
        }
        if (arr[i] < mn) {
            mn = arr[i];
            min_index = i;
        }
    }

    if (mx == 0 || mn == 0) {
        for (int i = 0; i < min_index; i++) {
            arr[i] = 0;
        }
    }

    cout << "Final array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " | ";
    }

    return 0;
}
