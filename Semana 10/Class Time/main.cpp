#include <iostream>
#include <stdexcept>
#include "Time.h"

using namespace std;

// función para mostrar el tiempo en ambos formatos
void displayTime(const string& message, const Time& time) {
    cout << message << "\nUniversal time: " << time.toUniversalString()
         << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {
    Time t; // crea un objeto de tipo Time

    displayTime("Initial time:", t); // muestra el valor inicial

    t.setTime(13, 27, 6); // cambia la hora
    displayTime("After setTime:", t); // muestra el nuevo valor

    // intenta establecer una hora no válida
    try {
        t.setTime(99, 99, 99); // valores fuera de rango
    } catch (invalid_argument& e) {
        cout << "Exception: " << e.what() << "\n\n";
    }

    // muestra el valor después de intentar una hora no válida
    displayTime("After attempting to set an invalid time:", t);

    return 0;
}
