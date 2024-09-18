#include <iostream>
using namespace std;

int main() {
    int anterior = 1, actual = 2;
    int sumaPares = 0; // acumula la suma de los terminos pares

    while (actual <= 4000000) {
        if (actual % 2 == 0) {
            sumaPares += actual;
        }

        // siguiente termino
        int siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }

    cout << "La suma de los terminos pares menores a 4 millones es:" << sumaPares << endl;

    return 0;
}
