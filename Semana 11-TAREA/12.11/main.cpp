#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "Date.h"

int main() {
    const int mesActual = 11;  // cambiar para probar con otros meses

    // crear un vector de punteros de empleados
    std::vector<std::unique_ptr<Employee>> empleados;
    empleados.push_back(std::make_unique<SalariedEmployee>("Juan", "Pérez", "123-45-6789", 11, 5, 1985, 800.00));
    empleados.push_back(std::make_unique<SalariedEmployee>("Ana", "García", "987-65-4321", 6, 15, 1975, 1200.00));
    
    // procesar la nomina de cada empleado
    for (const auto& empleado : empleados) {
        double pago = empleado->ingresos();  // obtener los ingresos del empleado

        // Si el mes actual coincide con el mes de nacimiento, añadir bono de cumpleaños
        if (empleado->getFechaNacimiento().getMes() == mesActual) {
            pago += 100.00;  // Bono de cumpleaños
        }

        // Mostrar informacion del empleado y el pago calculado
        std::cout << empleado->toString() << "\nIngresos: $" << std::fixed << std::setprecision(2) << pago << "\n\n";
    }
    
    return 0;
}
