#include <iostream>
using namespace std;

bool esPrimo(int num) {
    if (num < 2) return false; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // no es primo
        }
    }
    return true; // es primo
}

void imprimirPrimo(int n) {
    cout << "Los primos menores son: ";
    for (int i = 2; i < n; i++) {
        if (esPrimo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int numero;

    cout << "Introduce un número: ";
    cin >> numero;

    imprimirPrimo(numero);

    return 0;
}
