#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"

using namespace std;

class Bank
{
private:
    vector<Account> accounts;

public:
    // File Functions
    void loadAccounts();
    void saveAccounts();

    // Account Operations
    void createAccount();
    void login();

    // Banking Operations
    void deposit(Account &acc);
    void withdraw(Account &acc);
    void transfer(Account &acc);
    void checkBalance(Account &acc);
    void changePin(Account &acc);

    // Utility
    int findAccount(int accountNumber);
    void displayAllAccounts();
};

#endif