#include "CreditLimits.hpp"

CreditLimits::CreditLimits()
{
    accountNumber = 0;
    beginnigBalance = 0.0f;
    newBalance = 0.0f;
    totalMonthCharges = 0.0f;
    totalMonthcredits = 0.0f;
    creditLimit = 0.0f;
}

CreditLimits::~CreditLimits()
{
}

//Setters

void CreditLimits::setAccountNumber(int accNo)
{
    accountNumber = accNo;
}

void CreditLimits::setBeginningBalance(double bBalance)
{
    beginnigBalance = bBalance;
}

void CreditLimits::setNewBalance()
{
    newBalance = (getBeginningBalance() + getTotalMonthCharges()) - getTotalMonthCredits();

    std::cout << "New Balance is "
              << newBalance
              << std::endl;
}

void CreditLimits::setTotalMonthCharges(double charges)
{
    totalMonthCharges = charges;
}

void CreditLimits::setTotalMonthCredits(double credits)
{
    totalMonthcredits = credits;
}

void CreditLimits::setCreditLimit(double cLimit)
{
    creditLimit = cLimit;
}

//Getters

int CreditLimits::getAccountNumber() const
{
    return accountNumber;
}

double CreditLimits::getBeginningBalance() const
{
    return beginnigBalance;
}

double CreditLimits::getNewBalance() const
{
    return newBalance;
}

double CreditLimits::getTotalMonthCharges() const
{
    return totalMonthCharges;
}

double CreditLimits::getTotalMonthCredits() const
{
    return totalMonthcredits;
}

double CreditLimits::getCreditLimit() const
{
    return creditLimit;
}

bool CreditLimits::isCreditLimitExceeded() const
{
    return (getCreditLimit() - getNewBalance() < 0) ? true : false;
}

void CreditLimits::printAccountInfo() const
{
    if (isCreditLimitExceeded())
    {
        std::cout << "Credit Limit Exceeded."
                  << std::endl;

        std::cout << std::setprecision(2)
                  << std::fixed;
        std::cout << "Account                              : "
                  << getAccountNumber()
                  << std::endl;
        std::cout << "Credit limit                         : "
                  << getCreditLimit()
                  << std::endl;
        std::cout << "Balance                              : "
                  << getNewBalance()
                  << std::endl;
    }
}

void CreditLimits::run()
{
    int itemp;
    std::cout << "\nEnter account Number (or -1 to exit) : ";
    std::cin >> itemp;

    setAccountNumber(itemp);

    if (getAccountNumber() != -1)
    {
        double dtemp;
        std::setprecision(2);
        std::cout << "Enter beginning balance              : ";
        std::cin >> dtemp;

        setBeginningBalance(dtemp);

        std::cout << "Enter total charges                  : ";
        std::cin >> dtemp;

        setTotalMonthCharges(dtemp);

        std::cout << "Enter total credits                  : ";
        std::cin >> dtemp;

        setTotalMonthCredits(dtemp);

        std::cout << "Enter credit limit                   : ";

        std::cin >> dtemp;

        setCreditLimit(dtemp);

        setNewBalance();
        printAccountInfo();
    }
}