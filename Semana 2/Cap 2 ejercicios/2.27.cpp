#include <iostream>
using namespace std;

int main() {
    char character;

    cout << "Ingresa un carácter: ";
    cin >> character;

    cout << "El entero equivalente de '" << character << "' es: " << static_cast<int>(character) << endl;

    return 0;
}
