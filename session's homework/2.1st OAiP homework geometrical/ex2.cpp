#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Xcord[4], Ycord[4];
    double perimetr;

    for (int i = 0; i < 4; i++) {
        cout << "x" << i + 1<< ":";
        cin >> Xcord[i];

        cout << "y" << i + 1<< ":";
        cin >> Ycord[i];
    }

    for (int i = 0; i < 4 ; i++) {
        cout << Xcord[i] << " ";
        cout << Ycord[i]<< " ";
    
    }

    perimetr = sqrt(pow(Xcord[1] - Xcord[0], 2) + pow(Ycord[1] - Ycord[0], 2)) + 
        sqrt(pow(Xcord[2] - Xcord[1], 2) + pow(Ycord[2] - Ycord[1], 2))   + 
        sqrt(pow(Xcord[3] - Xcord[2], 2) + pow(Ycord[3] - Ycord[2], 2)) + 
        sqrt(pow(Xcord[0] - Xcord[3], 2) + pow(Ycord[0] - Ycord[3], 2));
    cout << endl;
    cout << "perimetr = " << perimetr;

    return 0;
}
