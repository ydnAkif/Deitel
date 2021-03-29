#ifndef CHECKING_ACCOUNT_HPP
#define CHECKING_ACCOUNT_HPP

#include "Account.hpp"

class CheckingAccount : public Account
{
private:
    double transactionFee;
    void chargeFee();

public:
    CheckingAccount(double, double);

    virtual bool debit(double);
    virtual void credit(double);
};

#endif