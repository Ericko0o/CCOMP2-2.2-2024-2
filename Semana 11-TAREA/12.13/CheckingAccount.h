#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

// clase CheckingAccount que representa una cuenta corriente
class CheckingAccount : public Account {
public:
    // constructor que inicializa el balance y el costo por transaccion
    CheckingAccount(double initialBalance, double transactionFee)
        : Account(initialBalance), feePerTransaction(transactionFee) {}

    // sobrecarga del metodo withdraw para deducir el costo por transaccion
    bool withdraw(double amount) override {
        // verifica si el retiro es exitoso en la clase base
        if (Account::withdraw(amount)) {
            balance -= feePerTransaction; // deduce el costo por transaccion
            return true;
        }
        return false; // retiro fallido si no hay suficiente balance
    }

private:
    double feePerTransaction; // atributo que almacena el costo por cada transaccion
};

#endif
