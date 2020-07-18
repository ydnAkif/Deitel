#include <iostream>
#include "Account.hpp"

using namespace std;

Account::Account(int initialBalance)
{
    if (initialBalance >= 0)
    {
        accountBalance = initialBalance;
    }
    else
    {
        accountBalance = 0;
        cout << "Error: Unable to initialise balance. Invalid entry." << endl;
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
        cout << "Debit amount exceeded account balance." << endl;
    }
}