#include <iostream>
using namespace std;

int main() {
    int radio;
    const double pi = 3.14159;

    cout << "Ingresa el radio del círculo (número entero): ";
    cin >> radio;

    int diámetro = 2 * radio;
    double circunferencia = 2 * pi * radio;
    double área = pi * radio * radio;

    cout << "Diámetro: " << diámetro << endl;
    cout << "Circunferencia: " << circunferencia << endl;
    cout << "Área: " << área << endl;

    return 0;
}