#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

// clase SavingsAccount que representa una cuenta de ahorros
class SavingsAccount : public Account {
public:
    // constructor que inicializa el balance y la tasa de interes
    SavingsAccount(double initialBalance, double interestRate)
        : Account(initialBalance), interestRate(interestRate) {}

    // calcula el interes basado en el balance actual y la tasa de interes
    double calculateInterest() const {
        return balance * interestRate;
    }

private:
    double interestRate; // atributo que almacena la tasa de interes de la cuenta
};

#endif
