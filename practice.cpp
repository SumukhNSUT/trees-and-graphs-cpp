#include <iostream>
using namespace std;

void mirrorChar(char input) {
    if (input >= 'a' && input <= 'z') {
        cout << 'z' - (input - 'a');
    }
    else if (input >= 'A' && input <= 'Z') {
        cout << 'Z' - (input - 'A');
    }
    else {
        cout << "Enter a valid letter!" << endl;
    }
}

int main() {
    char input;
    cout << "Enter a character: ";
    cin >> input;

    mirrorChar(input);

    return 0;
}