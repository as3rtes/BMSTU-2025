#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Xcord[3], Ycord[3];
    double Pl_Proverk;


    for (int i = 0; i < 3; i++) {
        cout << "x" << i + 1<< ":";
        cin >> Xcord[i];

        cout << "y" << i + 1<< ":";
        cin >> Ycord[i];
    }

    for (int i = 0; i < 3 ; i++) {
        cout << Xcord[i] << " ";
        cout << Ycord[i]<< " ";
    
    }
    cout << endl;
    Pl_Proverk = ((Xcord[1] - Xcord[0]) * (Ycord[2] - Ycord[0])) - ((Ycord[1] - Ycord[0]) * (Xcord[2] - Xcord[0]));
    if (Pl_Proverk == 0) {
        cout << "This good! ";
    }
    else {
        cout << "No no no... ";
    }

    return 0;
}
