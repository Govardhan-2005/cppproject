#include <iostream>
#include "Bank.h"

using namespace std;

int main()
{
    Bank bank;

    // Load saved accounts
    bank.loadAccounts();

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        BANK MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Admin Menu\n";
        cout << "4. Exit\n";
        cout << "=====================================\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.login();
                break;

            case 3:
            {
                string password;

                cout << "\nAdmin Password : ";
                cin >> password;

                if(password == "admin123")
                {
                    int adminChoice;

                    do
                    {
                        cout << "\n========== ADMIN MENU ==========\n";
                        cout << "1. View All Accounts\n";
                        cout << "2. Back\n";
                        cout << "Choice : ";
                        cin >> adminChoice;

                        switch(adminChoice)
                        {
                            case 1:
                                bank.displayAllAccounts();
                                break;

                            case 2:
                                break;

                            default:
                                cout << "Invalid Choice.\n";
                        }

                    }while(adminChoice != 2);
                }
                else
                {
                    cout << "Wrong Password!\n";
                }

                break;
            }

            case 4:
                cout << "\nThank You For Using Banking System.\n";
                break;

            default:
                cout << "\nInvalid Choice.\n";
        }

    }while(choice != 4);

    return 0;
}