//problema 2

#include <iostream>
using namespace std;

int contarLetras(const string& cadena) {
    int contador = 0;
    for (char c : cadena) {

        if ((int(c) >= 97 && int(c) <= 122) || (int(c) >= 65 && int(c) <= 90)) {
            ++contador;
        }
    }
    return contador;
}

int main() {

    string cadena = "x#S&34s!K[}*lM$wz)D90;";
    int cantidadLetras = contarLetras(cadena);

    cout << "Cantidad: " << cantidadLetras << endl;

    return 0;
}
