#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// clase abstracta employee
class Employee {
public:
    // constructor que inicializa los datos basicos del empleado
    Employee(const std::string& first, const std::string& last, const std::string& ssn)
        : firstName(first), lastName(last), socialSecurityNumber(ssn) {}

    virtual ~Employee() = default;

    // funciones virtuales puras para obtener ingresos y representacion en texto
    virtual double earnings() const = 0;
    virtual std::string toString() const = 0;

protected:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
};

#endif
