#include <iostream>
#include <vector>
#include <memory>
#include "Employee.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"

// funcion principal del sistema de nomina
int main() {
    // vector para almacenar punteros a empleados de diferentes tipos
    std::vector<std::unique_ptr<Employee>> employees;

    // agregar trabajadores por pieza y por hora al vector
    employees.push_back(std::make_unique<PieceWorker>("Carlos", "Sanchez", "123-45-6789", 15.5, 300));
    employees.push_back(std::make_unique<HourlyWorker>("Maria", "Perez", "987-65-4321", 20.0, 45));

    // procesar y mostrar detalles de cada empleado
    for (const auto& employee : employees) {
        std::cout << employee->toString() << "\n"
                  << "Earnings: $" << employee->earnings() << "\n\n";
    }

    return 0;
}
