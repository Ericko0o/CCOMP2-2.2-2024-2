#include <iostream>
using namespace std;

int main() {
    int numero, suma = 0;

    cout << "Ingresa el numero (0 para terminar): ";
    cin >> numero;

    while (numero != 0) {
        suma += numero;
        cin >> numero;
    }

    cout << "La suma de los numeros ingresados es: " << suma << endl;

    return 0;
}
