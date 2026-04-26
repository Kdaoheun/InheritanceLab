#ifndef INHERITANCELAB_BANKACCOUNT_H
#define INHERITANCELAB_BANKACCOUNT_H
#include <string>
#include <iostream>

class BankAccount {
public:

    BankAccount();
    BankAccount(std::string accNum,std::string Holder, double bal);

    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);

    virtual ~BankAccount();


    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    void setAccountHolderName(const std::string &Holder);


    virtual void deposit(double amount);
    virtual void withdraw(double amount);

    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    bool operator>(const BankAccount &other) const;
    bool operator<(const BankAccount &other) const;
    bool operator==(const BankAccount &) const;


    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();

protected:
    double balance;

private:
    std::string accountNumber;
    std::string accountHolderName;
};

#endif //INHERITANCELAB_BANKACCOUNT_H