#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    Point p; //instancia
    p.print(); //para invocar los metodos de la instancia se utiliza el "."

    Point *ptr = &p; //ptr tiene la direccion de memoria de "p" -> instancia con punteros
    ptr -> print(); // para invocar los metodos de la instancia usando el puntero se utiliza el operador "->" (flechita)

    ptr->setX (5);
    ptr->print();

}