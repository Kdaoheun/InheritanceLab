#ifndef INHERITANCELAB_BANKACCOUNT_H
#define INHERITANCELAB_BANKACCOUNT_H
#include <string>
#include <iostream>

class BankAccount {
public:
    // Construct/Deconstruct
    BankAccount();
    BankAccount(std::string accNum,std::string Holder, double bal);

    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);

    virtual ~BankAccount();

    // Get/Set
    std::string getAccountNumber() const {return accountNumber;};
    std::string getAccountHolderName() const {return accountHolderName;};
    double getBalance() const {return balance;};

    void setAccountHolderName(const std::string &Holder) {accountHolderName = Holder;};

    // Deposit/Withdraw
    void deposit(double amount);
    virtual void withdraw(double amount);

    //Arithmetic Assignment Operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    //Comparison Operators
    bool operator>(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator==(const BankAccount& other) const;

    //Static Utility Functions
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();

protected:
    double balance;

private:
    std::string accountNumber;
    std::string accountHolderName;
};

#endif //INHERITANCELAB_BANKACCOUNT_H