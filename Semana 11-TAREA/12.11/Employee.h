#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee {
public:
    Employee(const std::string& nombre, const std::string& apellido, const std::string& ssn, int mesNac, int diaNac, int añoNac)
        : nombre(nombre), apellido(apellido), numeroSeguroSocial(ssn), fechaNacimiento(diaNac, mesNac, añoNac) {}

    virtual ~Employee() = default;

    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    Date getFechaNacimiento() const { return fechaNacimiento; }

    // funcion virtual pura para obtener ingresos, obliga a las clases derivadas a implementarla
    virtual double ingresos() const = 0;
    virtual std::string toString() const = 0;

private:
    std::string nombre;
    std::string apellido;
    std::string numeroSeguroSocial;
    Date fechaNacimiento;  // fecha de nacimiento del empleado
};

#endif
