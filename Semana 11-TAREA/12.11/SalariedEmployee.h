#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee.h"
#include <string>
#include <iomanip>
#include <sstream>

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(const std::string& nombre, const std::string& apellido, const std::string& ssn, int mesNac, int diaNac, int añoNac, double salario)
        : Employee(nombre, apellido, ssn, mesNac, diaNac, añoNac), salarioSemanal(salario) {}

    virtual double ingresos() const override {
        return salarioSemanal;
    }

    virtual std::string toString() const override {
        std::ostringstream salida;
        salida << "Empleado asalariado: " << getNombre() << " " << getApellido()
               << "\nSalario semanal: $" << std::fixed << std::setprecision(2) << salarioSemanal;
        return salida.str();
    }

private:
    double salarioSemanal;  // salario semanal fijo
};

#endif
