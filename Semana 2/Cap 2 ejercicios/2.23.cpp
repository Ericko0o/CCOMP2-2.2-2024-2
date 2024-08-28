#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, num4, num5;

    cout << "Ingresa cinco enteros separados por espacios: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    int mayor = num1;
    int menor = num1;

    if (num2 > mayor) {
        mayor = num2;
    }
    if (num3 > mayor) {
        mayor = num3;
    }
    if (num4 > mayor) {
        mayor = num4;
    }
    if (num5 > mayor) {
        mayor = num5;
    }

    // comprobacion
    if (num2 < menor) {
        menor = num2;
    }
    if (num3 < menor) {
        menor = num3;
    }
    if (num4 < menor) {
        menor = num4;
    }
    if (num5 < menor) {
        menor = num5;
    }

    cout << "El entero más grande es: " << mayor << endl;
    cout << "El entero más pequeño es: " << menor << endl;

    return 0;
}