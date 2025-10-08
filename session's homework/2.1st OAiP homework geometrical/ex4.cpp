#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Xcord[4], Ycord[4];
    double diagonal;

    cout << "Enter the vertices in order: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "x" << i + 1 << ":";
        cin >> Xcord[i];

        cout << "y" << i + 1 << ":";
        cin >> Ycord[i];
    }

    for (int i = 0; i < 4; i++) {
        cout << Xcord[i] << " ";
        cout << Ycord[i] << " ";

    }

    diagonal = sqrt(pow(Xcord[2] - Xcord[0], 2) + pow(Ycord[2] - Ycord[0], 2));
    cout << endl;
    cout << "Diagonal =" << diagonal;

    return 0;
}
