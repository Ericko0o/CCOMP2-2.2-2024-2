#include <iostream>

using namespace std;

// Ejemplo for
int main() {
    for (int x = 0; x < 10; x = x + 1)
        cout << x << "\n";
    return 0;
}

// Ejemplo while
int main() {
    int x = 0;
    while (x < 10)
        x = x + 1;

    cout << "x is " << x << "\n";
    return 0;
}


//Ejemplo Switch case
int main() {
    int x = 6;
    switch (x) {
        case 1:
            cout << "x is 1\n";
            break;
        case 2:
        case 3:
            cout << "x is 2 or 3";
            break;
        default:
            cout << "x is not 1, 2, or 3";
    }
    return 0;
}
