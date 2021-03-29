#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

class SavingsAccount
{
private:
    double savingsBalance;
    static double annualInterestRate;

public:
    SavingsAccount(double);
    ~SavingsAccount();
    void calculateMonthlyInterest();
    static void modifyInterestRate(double);
    void printBalance() const;
};

#endif