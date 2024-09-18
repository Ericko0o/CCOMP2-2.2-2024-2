#include <iostream>
using namespace std;

// Función para verificar si un número es palíndromo
bool esPalindromo(int num) {
    int original = num, invertido = 0, digito;

    while (num > 0) {
        digito = num % 10;
        invertido = invertido * 10 + digito;
        num /= 10;
    }

    return original == invertido;
}

int main() {
    int mayorPalindromo = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) { 
            int producto = i * j;

            // verificacion de si es palindromo y mayor al anterior
            if (esPalindromo(producto) && producto > mayorPalindromo) {
                mayorPalindromo = producto;
            }
        }
    }

    cout << "El mayor palindromo hecho del producto de dos numeros de 3 digitos es: " << mayorPalindromo << endl;

    return 0;
}
