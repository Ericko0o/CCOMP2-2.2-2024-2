// Problema 2

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "ingresa un numero entero: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            cout << i;
            if (i < N - 1) {
                cout << ",";
            }
        }
    }
    cout << endl;
    return 0;
}
