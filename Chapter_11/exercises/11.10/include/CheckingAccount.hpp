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

    bool debit(double);
    void credit(double);
};

#endif