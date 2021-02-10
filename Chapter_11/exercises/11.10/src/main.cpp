#include <iostream>
#include <iomanip>
#include "Account.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"

int main(int argc, char const *argv[])
{
    Account account1(50.0);
    SavingsAccount account2(25.0, .03);
    CheckingAccount account3(80.0, 1.0);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "account1 balance: $" << account1.getBalance() << std::endl;
    std::cout << "account2 balance: $" << account2.getBalance() << std::endl;
    std::cout << "account3 balance: $" << account3.getBalance() << std::endl;

    std::cout << "\nAttempting to debit $25.00 from account1." << std::endl;
    account1.debit(25.0);
    std::cout << "\nAttempting to debit $30.00 from account2." << std::endl;
    account2.debit(30.0);
    std::cout << "\nAttempting to debit $40.00 from account3." << std::endl;
    account3.debit(40.0);

    std::cout << "\naccount1 balance: $" << account1.getBalance() << std::endl;
    std::cout << "\naccount2 balance: $" << account2.getBalance() << std::endl;
    std::cout << "\naccount3 balance: $" << account3.getBalance() << std::endl;

    std::cout << "\nCrediting $40.00 to account1." << std::endl;
    account1.credit(40.0);
    std::cout << "\nCrediting $65.00 to account2." << std::endl;
    account2.credit(65.0);
    std::cout << "\nCrediting $20.00 to account3." << std::endl;
    account3.credit(20.0);

    std::cout << "\naccount1 balance: $" << account1.getBalance() << std::endl;
    std::cout << "\naccount2 balance: $" << account2.getBalance() << std::endl;
    std::cout << "\naccount3 balance: $" << account3.getBalance() << std::endl;

    double interestEarned = account2.calculateInterest();
    std::cout << "\nAdding $" << interestEarned << " interest to account2." << std::endl;
    account2.credit(interestEarned);

    std::cout << "\nNew account2 balance: $" << account2.getBalance() << std::endl;

    return 0;
}
