#include <iostream>

using namespace std;

int main() {
    int x = 10;	
    cout << &x << endl;  // Imprime el valor de x

    int *ptr = &x;  // Asigna la dirección de x al puntero ptr
    cout << ptr << endl;  // Imprime la dirección de x

    int y = 1000;
    cout << &y << endl;  // Imprime el valor de y
//    ptr = y; error
//   *ptr = y; error
    ptr = 8y;
    cout << ptr << endl;
    return 0;
}

