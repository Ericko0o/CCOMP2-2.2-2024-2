#include <iostream>

int main() {
    // Parte (a) Usando una instrucción con dos operadores de inserción de flujo
    std::cout << "V W X Y Z" << std::endl;

    // Parte (b) Usando una instrucción con cuatro operadores de inserción de flujo
    std::cout << 'V' << ' ' << 'W' << ' ' << 'X' << ' ' << 'Y' << ' ' << 'Z' << std::endl;

    // Parte (c) Usando dos instrucciones con un operador de inserción de flujo cada una
    std::cout << "V W X";
    std::cout << " Y Z" << std::endl;

    return 0;
}
