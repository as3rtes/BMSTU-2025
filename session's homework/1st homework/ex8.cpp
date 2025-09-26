#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    char targetChar = 'o';
    char targetChar1 = 'i';
    char targetChar2 = 'u';
    char targetChar3 = 'y';
    char targetChar4 = 'e';
    char targetChar5 = 'a';
    char targetChar6 = 'O';
    char targetChar7 = 'I';
    char targetChar8 = 'U';
    char targetChar9 = 'Y';
    char targetChar10 = 'E';
    char targetChar11 = 'A';
    int count = 0;
    cout << "Enter text: ";
    getline(cin, text);
    for (char c : text) {
        if ((c == targetChar) || (c == targetChar1) || 
            (c == targetChar2) || (c == targetChar3) || 
            (c == targetChar4) || (c == targetChar5) || 
            (c == targetChar6) || (c == targetChar7) || 
            (c == targetChar8) || (c == targetChar9) || 
            (c == targetChar10) || (c == targetChar11)) {
            count++;
        }
    }

    std::cout << "Vowels: " << count;

    return 0;
}
