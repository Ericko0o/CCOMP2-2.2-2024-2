// Problema 3

#include <iostream>
using namespace std;

bool primo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "ingresa un numero entero: ";
    cin >> n;

    cout << "numeros primos menores a " << n << ": ";
    for (int i = 2; i < n; i++) {
        if (primo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
