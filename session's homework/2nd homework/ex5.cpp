#include <iostream>
using namespace std;


int main() {
    const int n = 10;
    int arr[n];
    int mx = -1000000;
    int mn = 1000000;
    int min_index = 0, max_index = 0;


    for (int i = 0; i < n; i++) {
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

    if (min_index == 4 && max_index == 9) {
        cout << "Avg:" << (mx + mn) / 2;
    }
    else {
        cout << "shit, god damh";
    }

    return 0;
}
