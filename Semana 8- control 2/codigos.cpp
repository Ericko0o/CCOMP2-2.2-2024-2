#include <iostream>
using namespace std;


int main() {
    int x = 10;    // La variable 'x' se inicializa con el valor 10.
    int y = 5;     // La variable 'y' se inicializa con el valor 5.

    int &ptr = ++x; // 'x' se incrementa a 11, 'ptr' es una referencia a 'x' (ahora 11).
    cout << ptr++ << endl; // Imprime '11' y luego 'ptr' (que es 'x') se incrementa a 12.

    int arr[] = {1, 2, 0, 4, 9, 10}; // Arreglo con los valores {1, 2, 0, 4, 9, 10}.
    int i = 0; // 'i' se inicializa en 0.

    while (arr[i]) {  // Mientras el valor en 'arr[i]' sea diferente de 0:
        if (x % 2) {  // Verifica si 'x' es impar. En este punto, 'x' es 12, así que no entra aquí (12 % 2 == 0).
            break;    // No se ejecuta porque 'x' es par.
        }
        else {
            cout << arr[i] << endl; // Imprime 'arr[0]', que es 1.
        }
        cout << x++ << endl; // Imprime el valor actual de 'x' (12) y luego 'x' se incrementa a 13.
        i++; // Incrementa 'i' a 1.
    }

    // El bucle termina porque en la segunda iteración, 'x' será impar (13), 
    // por lo tanto, la condición 'x % 2' se cumple y el 'break' detiene el bucle.
}


