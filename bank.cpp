#include "Bank.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// Search account by account number
int Bank::findAccount(int accountNumber)
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getAccountNumber() == accountNumber)
            return i;
    }

    return -1;
}

// Create New Account
void Bank::createAccount()
{
    int accNo;
    string name;
    string pin;
    double balance;

    cout << "\nEnter Account Number : ";
    cin >> accNo;

    if (findAccount(accNo) != -1)
    {
        cout << "Account already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Customer Name : ";
    getline(cin, name);

    cout << "Enter 4-digit PIN : ";
    cin >> pin;

    cout << "Enter Opening Balance : ";
    cin >> balance;

    Account acc(accNo, name, pin, balance);

    accounts.push_back(acc);

    saveAccounts();

    cout << "\nAccount Created Successfully.\n";
}

// Login
void Bank::login()
{
    int accNo;
    string pin;

    cout << "\nAccount Number : ";
    cin >> accNo;

    cout << "PIN : ";
    cin >> pin;

    int index = findAccount(accNo);

    if(index == -1)
    {
        cout << "\nAccount Not Found.\n";
        return;
    }

    if(!accounts[index].verifyPin(pin))
    {
        cout << "\nInvalid PIN.\n";
        return;
    }

    int choice;

    do
    {
        cout << "\n========== CUSTOMER MENU ==========\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Change PIN\n";
        cout << "6. Display Account\n";
        cout << "7. Logout\n";

        cout << "\nChoice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            checkBalance(accounts[index]);
            break;

        case 2:
            deposit(accounts[index]);
            saveAccounts();
            break;

        case 3:
            withdraw(accounts[index]);
            saveAccounts();
            break;

        case 4:
            transfer(accounts[index]);
            saveAccounts();
            break;

        case 5:
            changePin(accounts[index]);
            saveAccounts();
            break;

        case 6:
            accounts[index].display();
            break;

        case 7:
            cout << "\nLogged Out Successfully.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while(choice != 7);
}

// Deposit
void Bank::deposit(Account &acc)
{
    double amount;

    cout << "\nEnter Amount : ";
    cin >> amount;

    acc.deposit(amount);

    cout << "Deposit Successful.\n";
}

// Withdraw
void Bank::withdraw(Account &acc)
{
    double amount;

    cout << "\nEnter Amount : ";
    cin >> amount;

    if(acc.withdraw(amount))
        cout << "Withdrawal Successful.\n";
    else
        cout << "Insufficient Balance.\n";
}

// Transfer
void Bank::transfer(Account &sender)
{
    int receiverAcc;
    double amount;

    cout << "\nReceiver Account Number : ";
    cin >> receiverAcc;

    int index = findAccount(receiverAcc);

    if(index == -1)
    {
        cout << "Receiver Account Not Found.\n";
        return;
    }

    cout << "Amount : ";
    cin >> amount;

    if(sender.withdraw(amount))
    {
        accounts[index].deposit(amount);
        cout << "Transfer Successful.\n";
    }
    else
    {
        cout << "Insufficient Balance.\n";
    }
}

// Check Balance
void Bank::checkBalance(Account &acc)
{
    cout << "\nCurrent Balance : Rs. "
         << fixed << setprecision(2)
         << acc.getBalance()
         << endl;
}

// Change PIN
void Bank::changePin(Account &acc)
{
    string newPin;

    cout << "\nEnter New PIN : ";
    cin >> newPin;

    acc.setPin(newPin);

    cout << "PIN Changed Successfully.\n";
}

// Display All Accounts
void Bank::displayAllAccounts()
{
    cout << "\n========== ALL ACCOUNTS ==========\n";

    for(Account &acc : accounts)
    {
        acc.display();
    }
}