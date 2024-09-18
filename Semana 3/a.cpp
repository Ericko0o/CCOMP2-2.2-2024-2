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

int main() {
    int numero;

    cout << "Numero a evaluar:";
    cin >> numero;

    if (esPrimo(numero)) {
        cout << "el numero es primo" << endl;
    } else {
        cout << "el numero no es primo" << endl;
    }

    return 0;
}
