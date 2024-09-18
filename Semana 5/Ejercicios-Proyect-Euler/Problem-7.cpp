#include <iostream>
using namespace std;

bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int contadorPrimos = 0;
    int numero = 1;
    int primoEncontrado = 0;

    while (contadorPrimos < 10001) {
        numero++;
        if (esPrimo(numero)) {
            contadorPrimos++;
            primoEncontrado = numero;
        }
    }

    cout << "El primo numero 10001 es:" << primoEncontrado << endl;

    return 0;
}
