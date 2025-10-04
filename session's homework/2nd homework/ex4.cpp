#include <iostream>
using namespace std;

int main() {
    const int size = 15;
    double arr[size];
    double mx = -1000000;
    double mn = 1000000;
    int index_min = 0, index_max = 0;


    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];

        if (arr[i] > mx) {
            mx = arr[i];
            index_max = i;
        }

        if (arr[i] < mn) {
            mn = arr[i];
            index_min = i;
        }
    }

    if (index_max < index_min) {
        cout << "The product of numbers:" << mx * mn;
    }
    else {
        cout << "All true!";
    }

    return 0;
}
