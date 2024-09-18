#include <iostream>
#include <string>
using namespace std;

class Account {
    public:
        explicit Account(string accountName, int initialBalance)
                : name{accountName} {
            if(initialBalance > 0) {
                balance = balance + initialBalance;
            }
        }

        void deposit(int depositAmount) {
            if(depositAmount > 0) {
                balance = balance + depositAmount;
            }
        }

        void withdraw(int withdrawAmount) {
            if(withdrawAmount > balance) {
                cout << "Fondos insuficientes" << std::endl;
            }    
            else {
                balance = balance - withdrawAmount;
            }

            
        }

        int getBalance() const {
            return balance;
        }

        void setName(std::string accountName) {
            name = accountName;
        }
        std::string getName() const {
            return name;
        }
    private:
        std::string name;
        int balance{0};
};