#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "Account.hpp"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(double, double);
    double calculateInterest() const;
};

#endif