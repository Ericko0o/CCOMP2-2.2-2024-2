#include <iostream> 
using namespace std;

int main() {
    // Este programa calcula el producto de tres números enteros
    int x = 0;
    int y = 0;
    int z = 0;
    int result = 0;

    // Pedimos al usuario que ingrese tres números enteros
    cout << "Please enter three integers: ";
    cin >> x >> y >> z;

    // Calculamos el producto de los tres números y lo almacenamos en result
    result = x * y * z;

    // Mostramos el resultado al usuario
    cout << "The product is " << result << endl;

    return 0;
