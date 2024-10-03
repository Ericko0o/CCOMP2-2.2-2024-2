//problema 1

#include <iostream>
using namespace std;

bool esPrimo(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) { 
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int contarPrimos(int arr[], int tamaño) {
    int contador = 0;
    for (int i = 0; i < tamaño; ++i) {
        if (esPrimo(arr[i])) {
            ++contador;
        }
    }
    return contador;
}

int main() {

    int arreglo[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    int cantidadPrimos = contarPrimos(arreglo, tamaño);

    cout << "Cantidad de primos: " << cantidadPrimos << endl;

    return 0;
}
