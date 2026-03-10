//Author: Kobe Daoheung
//Date: 3/9/26
//Assignment: Challenge: Enhancing the Bank Account Management System
//Menu code started from: https://yosemite.instructure.com/courses/70824/pages/c++-menu-program-code-sample

#include <iostream>
#include  <vector>
#include  <limits>
#include <memory>
#include <string>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

//function prototypes
int displayMenu();
void runMenu(std::vector<std::unique_ptr<BankAccount>>& accounts);

int main() {
    std::vector<std::unique_ptr<BankAccount>> accounts;

    // Initialization
    runMenu(accounts);

    // Cleanup
    return 0;
}

// Function to display the menu
int displayMenu() {
    std::cout << "\nBank Account Menu\n";
    std::cout << "1. Add Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Show Accounts\n";
    std::cout << "5. Update Account Holder Name\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}
// Function to run the menu loop
void runMenu(std::vector<std::unique_ptr<BankAccount>>& accounts ) {
    int choice; //The menu selection
    do {
        //Get a menu selection
        choice = displayMenu();
        //Carry out the menu selection (should call functions)
        switch (choice) {
            case 1: {
                std::cout << "Add Account\n";

                BankAccount Naccount = BankAccount::createAccountFromInput();

                bool notnew = false;
                for (int i = 0; i < accounts.size(); ++i) {
                    if (accounts.at(i).getAccountNumber() == Naccount.getAccountNumber()) {
                        notnew = true;
                        break;
                    }
                }

                if (notnew) {
                    std::cout << "Account number already exists. Please choose a new account number" << std::endl;
                }
                else {
                    accounts.push_back(Naccount);
                    std::cout << "Account created successfully." << std::endl;
                }
                break;
            }
            case 2: {
                std::string accNum;
                double amount;

                std::cout << "Deposit\n";

                std::cout << "Enter account Number: ";
                std::cin >> accNum;

                bool found = false;

                for (int i = 0; i < accounts.size(); ++i) {
                    if (accounts.at(i)->getAccountNumber() == accNum) {
                        found = true;
                        std::cout << "Account number: " << accounts.at(i)->getAccountNumber() << std::endl;
                        std::cout << "Account Holder Name: " << accounts.at(i)->getAccountHolderName() << std::endl;
                        std::cout << "Enter deposit amount: ";
                        std::cin >> amount;
                        accounts.at(i) += amount;
                        break;
                    }
                }
                if (!found) {std::cout << "Account not found." << std::endl;}
                break;
            }
            case 3: {
                std::string accNum;
                double amount;

                std::cout << "Withdraw\n";

                std::cout << "Enter account Number: ";
                std::cin >> accNum;

                bool found = false;

                for (int i = 0; i < accounts.size(); ++i) {
                    if (accounts.at(i)->getAccountNumber() == accNum) {
                        found = true;
                        std::cout << "Account number: " << accounts.at(i)->getAccountNumber() << std::endl;
                        std::cout << "Account Holder Name: " << accounts.at(i)->getAccountHolderName() << std::endl;
                        std::cout << "Enter withdraw amount: ";
                        std::cin >> amount;
                        accounts.at(i) -= amount;
                        break;
                    }
                }
                if (!found) {std::cout << "Account not found." << std::endl;}
                break;
            }
            case 4: {
                std::cout << "Show Accounts\n";
                if (accounts.empty()) {
                    std::cout << "No accounts exist." << std::endl;
                }
                else {
                    for (int i = 0; i < accounts.size(); ++i) {
                        BankAccount::printAccount(accounts.at(i));
                    }
                }
                break;
            }
                case 5: {
                std::string accNum, accHolderName;

                std::cout << "Update Account Holder Name\n";
                std::cout << "Enter account Number: ";
                std::cin >> accNum;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                bool found = false;

                for (int i = 0; i < accounts.size(); ++i) {
                    if (accounts.at(i)->getAccountNumber() == accNum) {
                        found = true;
                        std::cout << "Enter new account holder name: ";
                        std::getline(std::cin, accHolderName);
                        accounts.at(i)->setAccountHolderName(accHolderName);
                        std::cout << "Account holder name updated successfully." << std::endl;
                    }
                }
                if (!found) {std::cout << "Account not found." << std::endl;}
                break;
            }
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        //End of menu selection if 0 was selected
    } while (choice != 0);
}

