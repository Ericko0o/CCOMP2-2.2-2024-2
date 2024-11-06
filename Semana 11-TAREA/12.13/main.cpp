#include <iostream>
#include <vector>
#include <memory>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
    // vector para almacenar punteros unicos a objetos Account
    std::vector<std::unique_ptr<Account>> accounts;
    // crea una cuenta de ahorros con balance inicial de 1000 y tasa de interes de 3%
    accounts.push_back(std::make_unique<SavingsAccount>(1000.0, 0.03));
    // crea una cuenta corriente con balance inicial de 1000 y costo de transaccion de 1
    accounts.push_back(std::make_unique<CheckingAccount>(1000.0, 1.0));

    // recorre todas las cuentas en el vector
    for (auto& account : accounts) {
        double depositAmount, withdrawAmount;

        // muestra el balance actual de la cuenta
        std::cout << "\nSaldo actual: $" << account->checkBalance() << "\n";

        // solicita al usuario que ingrese el monto a depositar
        std::cout << "Ingrese monto a depositar: ";
        std::cin >> depositAmount;
        account->addFunds(depositAmount); // agrega fondos a la cuenta

        // solicita al usuario que ingrese el monto a retirar
        std::cout << "Ingrese monto a retirar: ";
        std::cin >> withdrawAmount;
        // intenta retirar el monto especificado, verifica si es exitoso
        if (!account->withdraw(withdrawAmount)) {
            std::cout << "Monto a retirar excede el saldo de la cuenta.\n";
        }

        // verifica si la cuenta actual es una cuenta de ahorros
        if (SavingsAccount* savings = dynamic_cast<SavingsAccount*>(account.get())) {
            // calcula y aplica el interes a la cuenta de ahorros
            double interest = savings->calculateInterest();
            savings->addFunds(interest);
            std::cout << "Interes de $" << interest << " aplicado.\n";
        }

        // muestra el balance actualizado de la cuenta
        std::cout << "Saldo actualizado: $" << account->checkBalance() << "\n";
    }

    return 0;
}
