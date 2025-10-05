#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Xcord[3], Ycord[3];

    for (int i = 0; i < 3; i++) {
        cout << "x" << i + 1 << ':';
        cin >> Xcord[i];

        cout << "y" << i + 1 << ':';
        cin >> Ycord[i];
    }

    double Square = 0.5 * abs(Xcord[0] * (Ycord[1] - Ycord[2]) + Xcord[1] * (Ycord[2] - Ycord[0]) + Xcord[2] * (Ycord[0] - Ycord[1]));
    cout << "square is: " << Square;

    return 0;
}
