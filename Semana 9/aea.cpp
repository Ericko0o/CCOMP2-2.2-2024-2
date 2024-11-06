#include <iostream>
using namespace std;
//Buscar n° de letras
int buscarLetra(char m[2][2]) {
    int contador = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (m[i][j]==97||m[i][j]==65){
                contador++;
            }
        }
    }
    return contador;
}
int main() {
    char m[2][2] = {
        {'a', 'b'},
        {'A', 'c'}
    };
    int apariciones = buscarLetra(m);
    cout<< apariciones << endl;
    return 0;
}







