// Fig. 8.7: fig08_07.cpp
// Paso por referencia con un argumento puntero para elevar al cubo el valor de una variable.
#include <iostream>
using namespace std;

void cubeByReference(int*); // prototipo 

int main() {
    int number{5};

    cout << "El valor original de number es " << number;
    cubeByReference(&number); // pasa la dirección de number a cubeByReference
    cout << "\nEl nuevo valor de number es " << number << endl;
}

// calcula el cubo de *nPtr; modifica la variable number en main
void cubeByReference(int* nPtr) { 
    *nPtr = *nPtr * *nPtr * *nPtr; // eleva al cubo *nPtr 
}
