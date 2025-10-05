#include <iostream>
using namespace std;

int main() {
    double Xcord[3], Ycord[3];

    for (int i = 0; i < 3; i++) {
        cout << "x" << i + 1 << ':';
        cin >> Xcord[i];

        cout << "y" << i + 1 << ':';
        cin >> Ycord[i];
    }

    double Cx = (Xcord[0] + Xcord[1] + Xcord[2]) / 3.0;
    double Cy = (Ycord[0] + Ycord[1] + Ycord[2]) / 3.0;

    cout << "Cx: " << Cx << endl;
    cout << "Cy: " << Cy;

    return 0;
}
