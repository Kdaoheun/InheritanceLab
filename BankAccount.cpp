#include "BankAccount.h"
#include <iostream>
#include <limits>

// Construct/Deconstruct
BankAccount::BankAccount() {
    accountNumber = "None";
    accountHolderName = "None";
    balance = 0.0;
}

BankAccount::BankAccount(std::string accNum, std::string Holder,double bal) {
    accountNumber = accNum;
    accountHolderName = Holder;
    balance = bal;
}

BankAccount::BankAccount(const BankAccount &other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}

BankAccount& BankAccount::operator=(const BankAccount &other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}

BankAccount::~BankAccount() {}

//Operator Overload
BankAccount& BankAccount::operator+=(double amount) {
    deposit(amount);
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    withdraw(amount);
    return *this;
}

bool BankAccount::operator>(const BankAccount &other) const {
    return balance > other.balance;
}

bool BankAccount::operator<(const BankAccount &other) const {
    return balance < other.balance;
}

bool BankAccount::operator==(const BankAccount &other) const {
    return accountNumber == other.accountNumber;
}

void BankAccount::printAccount(const BankAccount &account) {
    std::cout << "Account number: " << account.accountNumber << std::endl;
    std::cout << "Account Holder Name: " << account.accountHolderName << std::endl;
    std::cout << "Account Balance: " << account.balance << std::endl;
}

BankAccount BankAccount::createAccountFromInput() {
    std::string accNum, Holder;
    double bal;
    std::cout << "Enter account Number: ";
    std::cin >> accNum;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter account Holder Name: ";
    std::getline(std::cin, Holder);

    std::cout << "Enter account Balance: ";
    std::cin >> bal;

    return BankAccount(accNum, Holder, bal);
}

// Deposit and Withdraw
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited $" << amount << std::endl;
    }
    else {
        std::cout << "Deposit amount must be greater than zero." << std::endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdraw amount must be greater than zero." << std::endl;
    }
    else if (amount > balance) {
        std::cout << "Insufficient funds." << std::endl;
    }
    else {
        balance -= amount;
        std::cout << "Withdrew $" << amount << std::endl;
    }
}