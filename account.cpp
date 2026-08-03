#include "Account.h"
#include <iomanip>
#include <sstream>

using namespace std;

// Default Constructor
Account::Account()
{
    accountNumber = 0;
    name = "";
    pin = "";
    balance = 0.0;
}

// Parameterized Constructor
Account::Account(int accNo, string name, string pin, double balance)
{
    accountNumber = accNo;
    this->name = name;
    this->pin = pin;
    this->balance = balance;
}

// Setters
void Account::setAccountNumber(int accNo)
{
    accountNumber = accNo;
}

void Account::setName(string name)
{
    this->name = name;
}

void Account::setPin(string pin)
{
    this->pin = pin;
}

void Account::setBalance(double balance)
{
    this->balance = balance;
}

// Getters
int Account::getAccountNumber() const
{
    return accountNumber;
}

string Account::getName() const
{
    return name;
}

string Account::getPin() const
{
    return pin;
}

double Account::getBalance() const
{
    return balance;
}

// Deposit Money
void Account::deposit(double amount)
{
    if(amount > 0)
        balance += amount;
}

// Withdraw Money
bool Account::withdraw(double amount)
{
    if(amount <= balance)
    {
        balance -= amount;
        return true;
    }

    return false;
}

// Verify PIN
bool Account::verifyPin(string enteredPin)
{
    return enteredPin == pin;
}

// Display Account Details
void Account::display() const
{
    cout << "\n-----------------------------------\n";
    cout << "Account Number : " << accountNumber << endl;
    cout << "Customer Name  : " << name << endl;
    cout << "Balance        : Rs. "
         << fixed << setprecision(2)
         << balance << endl;
    cout << "-----------------------------------\n";
}

// Convert Object to File Format
string Account::toFileString() const
{
    stringstream ss;

    ss << accountNumber << ","
       << name << ","
       << pin << ","
       << balance;

    return ss.str();
}