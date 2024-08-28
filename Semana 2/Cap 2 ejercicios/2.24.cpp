#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Ingresa el primer entero: ";
    cin >> num1;

    cout << "Ingresa el segundo entero: ";
    cin >> num2;

    if (num1 % 2 == 1) {
        cout << num1 << " es un número impar." << endl;
    } else {
        cout << num1 << " no es un número impar." << endl;
    }

    if (num2 % 2 == 1) {
        cout << num2 << " es un número impar." << endl;
    } else {
        cout << num2 << " no es un número impar." << endl;
    }

    int suma = num1 + num2;

    if (suma % 2 == 1) {
        cout << "La suma de los dos enteros es un número impar." << endl;
    } else {
        cout << "La suma de los dos enteros no es un número impar." << endl;
    }

    return 0;
}