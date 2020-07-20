#include <iostream>
#include "Account.hpp"

Account::Account(int initialBalance)
{
    if (initialBalance >= 0)
    {
        accountBalance = initialBalance;
    }
    else
    {
        accountBalance = 0;
        std::cout << "Error: Unable to initialise balance. Invalid entry."
                  << std::endl;
    }
}

int Account::getBalance()
{
    return accountBalance;
}

void Account::credit(int amount)
{
    if (amount > 0)
    {
        accountBalance += amount;
    }
}

void Account::debit(int amount)
{
    if (amount <= accountBalance)
    {
        accountBalance -= amount;
    }
    else
    {
        std::cout << "Debit amount exceeded account balance."
                  << std::endl;
    }
}