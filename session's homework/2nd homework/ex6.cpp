#include <iostream>
using namespace std;

int main() {
    const int num = 15;
    double arr[num];
    int min_index = 0, max_index = 0;
    int mx = -1000000;
    int mn = 1000000;



    for (int i = 0; i < num; i++) {
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

    if (min_index == 1 && max_index == 0) {
        for (int i = 0; i < num; i++) {
            arr[i] /= 2;
        }
    }

    cout << endl;
    cout << "Array / 2: ";
    for (int i = 0; i < num; i++) {
        cout << arr[i]<< " | ";
    }

    return 0;
}
