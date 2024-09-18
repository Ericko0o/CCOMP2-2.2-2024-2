#include <iostream>

int main() {

    // a)
    std::cout << "Welcome to the maximal heart rate calculator" << std::endl;

    int a, b, c;

    // d) Ingresar tres valores enteros
    std::cout << "Ingrese tres valores enteros: ";
    std::cin >> a >> b >> c;

    // b) Asignacion
    a = b * c;

    std::cout << "El producto de b y c es: " << a << std::endl;

    return 0;
}
