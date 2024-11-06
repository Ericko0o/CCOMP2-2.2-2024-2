#ifndef ACCOUNT_H
#define ACCOUNT_H

// clase base Account que representa una cuenta bancaria general
class Account {
public:
    // constructor que inicializa el balance, asigna 0 si el balance inicial es negativo
    explicit Account(double initialBalance) : balance(initialBalance >= 0 ? initialBalance : 0) {}

    // metodo para agregar fondos a la cuenta
    virtual void addFunds(double amount) {
        if (amount > 0) balance += amount;
    }

    // metodo para retirar fondos de la cuenta, retorna false si el monto excede el balance
    virtual bool withdraw(double amount) {
        if (amount > balance) {
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    // metodo para obtener el balance actual de la cuenta
    double checkBalance() const {
        return balance;
    }

    // destructor virtual para permitir comportamiento polimorfico en clases derivadas
    virtual ~Account() = default;

protected:
    double balance; // atributo para almacenar el balance de la cuenta
};

#endif
