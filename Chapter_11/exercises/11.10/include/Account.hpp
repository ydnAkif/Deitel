#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account
{
private:
    double balance;

public:
    Account(double);
    void credit(double);
    bool debit(double);
    void setBalance(double);
    double getBalance() const;
};

#endif