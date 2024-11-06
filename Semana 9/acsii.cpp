#include <iostream>
using namespace std;
bool esLetra(char c) {
    return ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) );
}
bool esMay(char c) {
    return (c >= 65 && c <= 90);
}
char convMin(char c) {
    return c+32;
}
bool esNumero(char c) {
    return (c >= 48 && c <= 57);
}
void evaluarCadena(char cad[]) {
    //char car = cadena[0];
    for (int i = 0; cad[i] != '\0'; i++) {
        if(esLetra(cad[i]))
            cad[i] = (esMay(cad[i]))?convMin(cad[i]):cad[i];    
        else {
            if(esNumero(cad[i]))
                cad[i] = '-';
        }
    }    
}
int main() {
    char cad[] = "HOLA345como&5estas";
    evaluarCadena(cad);
    cout << cad << endl;
    return 0;
}
