#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter num: ";
    cin >> num;
    if (num > 0) {
        cout << "Number > 0";
    }
    else if (num < 0) {
        cout << "Number < 0";
    }
    else {
        cout << "Zero";
    }
    return 0;
}
