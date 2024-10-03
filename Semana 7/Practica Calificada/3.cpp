//problema 3

#include <iostream>
using namespace std;

void elevarCuadrado(int arr[], int tamano) {
    for (int i = 0; i < tamano; ++i) {
        arr[i] = arr[i] * arr[i];
    }
}

int main() {

    int numeros[] = {1, 2, 3, 4, 5};
    int tam = sizeof(numeros) / sizeof(numeros[0]);


    cout << "Arreglo: ";
    for (int i = 0; i < tam; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    elevarCuadrado(numeros, tam);

    cout << "Arreglo al cuadrado: ";
    for (int i = 0; i < tam; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
