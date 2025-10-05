#include <iostream>
using namespace std;

int main() {
    const int size = 10;
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

    if (min_index == 4 && max_index == 1) {
        for (int i = min_index; i < size; i++) {
            arr[i] = mx;
        }
    }

    cout << "Final array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " | ";
    }

    return 0;
}
