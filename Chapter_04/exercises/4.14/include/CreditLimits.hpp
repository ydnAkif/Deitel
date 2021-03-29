#include <iostream>
#include <iomanip>
class CreditLimits
{
private:
    int accountNumber;
    double beginnigBalance, newBalance, totalMonthCharges,
        totalMonthcredits, creditLimit;

public:
    CreditLimits();
    ~CreditLimits();

    //Setters
    
    void setAccountNumber(int);
    void setBeginningBalance(double);
    void setNewBalance();
    void setTotalMonthCharges(double);
    void setTotalMonthCredits(double);
    void setCreditLimit(double);

    //Getters

    int getAccountNumber() const;
    double getBeginningBalance() const;
    double getNewBalance() const;
    double getTotalMonthCharges() const;
    double getTotalMonthCredits() const;
    double getCreditLimit() const;
    bool isCreditLimitExceeded() const;

    void printAccountInfo() const;
    void run();
};
