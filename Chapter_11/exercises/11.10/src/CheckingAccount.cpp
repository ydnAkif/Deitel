#include <iostream>
#include <stdexcept>
#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(double initBalance, double fee) : Account(initBalance)
{
    if (fee >= 0.0)
        transactionFee = fee;
    else
        throw std::invalid_argument("Transaction fee must be >= 0.0");
}

void CheckingAccount::credit(double amount)
{
    Account::credit(amount);
    chargeFee();
}

bool CheckingAccount::debit(double amount)
{
    bool succes = Account::debit(amount);

    if (succes)
    {
        chargeFee();
        return true;
    }
    else
        return false;
}

void CheckingAccount::chargeFee()
{
    Account::setBalance(getBalance() - transactionFee);
    std::cout << '$' << transactionFee << " transaction fee charged." << std::endl;
}