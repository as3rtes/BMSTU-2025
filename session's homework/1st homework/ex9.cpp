#include <iostream>
using namespace std;

int main() {
    int num;
    int co = 0;
    cout << "Enter num: ";
    cin >> num;

    for (int i = 1; i < num + 1; i++) {
        if (i % 2 == 0 || i % 5 == 0) {
            co += i;

        }
    }
    cout << "Summ: " << co;
    return 0;
}
