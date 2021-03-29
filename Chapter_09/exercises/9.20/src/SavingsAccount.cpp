#include <iostream>
#include <iomanip>
#include "SavingsAccount.hpp"

double SavingsAccount::annualInterestRate = 0.0;

SavingsAccount::SavingsAccount(double b)
{
    savingsBalance = b >= 0 ? b : 0;
}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::calculateMonthlyInterest()
{
    savingsBalance += savingsBalance * (annualInterestRate / 12.0);
}

void SavingsAccount::modifyInterestRate(double i)
{
    annualInterestRate = ((i >= 0.0 && i <= 1.0) ? i : 0.03);
}

void SavingsAccount::printBalance() const
{
    std::cout << std::setiosflags(std::ios::fixed | std::ios::showpoint)
              << '$' << std::setprecision(2) << savingsBalance
              << std::resetiosflags(std::ios::fixed | std::ios::showpoint);
}