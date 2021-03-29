#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account
{
private:
    double balance;

public:
    Account(double);
    virtual void credit(double);
    virtual bool debit(double);
    void setBalance(double);
    double getBalance() const;
};

#endif