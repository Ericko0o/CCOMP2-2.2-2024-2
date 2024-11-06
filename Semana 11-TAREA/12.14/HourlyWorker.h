#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"
#include <string>
#include <sstream>
#include <iomanip>

class HourlyWorker : public Employee {
public:
    // constructor que inicializa los datos basicos, tarifa por hora y horas trabajadas
    HourlyWorker(const std::string& first, const std::string& last, const std::string& ssn,
                 double hourlyWage, double hoursWorked)
        : Employee(first, last, ssn), wage(hourlyWage), hours(hoursWorked) {}

    // calcula el salario incluyendo tiempo extra si las horas superan 40
    virtual double earnings() const override {
        if (hours <= 40) {
            return wage * hours;
        } else {
            return (40 * wage) + ((hours - 40) * wage * 1.5);
        }
    }

    // convierte los datos del trabajador a string para impresion
    virtual std::string toString() const override {
        std::ostringstream output;
        output << "Hourly Worker: " << firstName << " " << lastName
               << "\nSSN: " << socialSecurityNumber
               << "\nHourly wage: $" << std::fixed << std::setprecision(2) << wage
               << "\nHours worked: " << hours;
        return output.str();
    }

private:
    double wage;  // tarifa por hora del trabajador
    double hours; // horas trabajadas en la semana
};

#endif
