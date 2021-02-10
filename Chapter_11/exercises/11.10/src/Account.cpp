#include <iostream>
#include <stdexcept>
#include "Account.hpp"

Account::Account(double initialBalance)
{
    if (initialBalance >= 0.0)
        balance = initialBalance;
    else
        throw std::invalid_argument("Initial balance cannot be negative");
}

void Account::credit(double amount)
{
    balance = balance + amount;
}

bool Account::debit(double amount)
{
    if (amount > balance)
    {
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return false;
    }
    else
    {
        balance = balance - amount;
        return true;
    }
}

void Account::setBalance(double newBalance)
{
    balance = newBalance;
}

double Account::getBalance() const
{
    return balance;
}