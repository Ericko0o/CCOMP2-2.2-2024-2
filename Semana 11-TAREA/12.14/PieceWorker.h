#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include "Employee.h"
#include <string>
#include <sstream>
#include <iomanip>

class PieceWorker : public Employee {
public:
    // constructor que inicializa el nombre, ssn, salario por pieza y piezas producidas
    PieceWorker(const std::string& first, const std::string& last, const std::string& ssn,
                double wagePerPiece, int piecesProduced)
        : Employee(first, last, ssn), wage(wagePerPiece), pieces(piecesProduced) {}

    // calcula el pago multiplicando la tarifa por pieza por la cantidad producida
    virtual double earnings() const override {
        return wage * pieces;
    }

    // convierte los datos del trabajador a string para impresion
    virtual std::string toString() const override {
        std::ostringstream output;
        output << "Piece Worker: " << firstName << " " << lastName
               << "\nSSN: " << socialSecurityNumber
               << "\nWage per piece: $" << std::fixed << std::setprecision(2) << wage
               << "\nPieces produced: " << pieces;
        return output.str();
    }

private:
    double wage;  // salario por pieza producida
    int pieces;   // cantidad de piezas producidas
};

#endif
