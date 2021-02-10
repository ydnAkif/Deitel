#include <stdexcept>
#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(double initialBalance, double rate) : Account(initialBalance)
{
    if (rate >= 0.0)
        interestRate = rate;
    else
        throw std::invalid_argument("Interest rate must be >= 0.0");
}

double SavingsAccount::calculateInterest() const
{
    return getBalance() * interestRate;
}
