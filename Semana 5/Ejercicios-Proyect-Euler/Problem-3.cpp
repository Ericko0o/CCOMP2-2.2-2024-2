#include <iostream>
using namespace std;

int main() {
    long long numero = 600851475143;
    long long factor = 2;
    long long mayorFactorPrimo = 0;

    // dividimos el numero por sus factores primos
    while (numero > 1) {
        if (numero % factor == 0) {
            mayorFactorPrimo = factor;
            numero /= factor;
        } else {
            factor++;
        }
    }

    cout << "El mayor factor primo de 600851475143 es: " << mayorFactorPrimo << endl;

    return 0;
}
