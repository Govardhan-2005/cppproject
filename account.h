#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    int accountNumber;
    string name;
    string pin;
    double balance;

public:
    Account();
    Account(int accNo, string name, string pin, double balance);

    // Setters
    void setAccountNumber(int accNo);
    void setName(string name);
    void setPin(string pin);
    void setBalance(double balance);

    // Getters
    int getAccountNumber() const;
    string getName() const;
    string getPin() const;
    double getBalance() const;

    // Banking Functions
    void deposit(double amount);
    bool withdraw(double amount);
    bool verifyPin(string enteredPin);
    void display() const;

    // File Functions
    string toFileString() const;
};

#endif