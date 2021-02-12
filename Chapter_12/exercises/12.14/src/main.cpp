#include <iostream>
#include <iomanip>
#include <vector>
#include "Account.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"

int main(int argc, char const *argv[])
{
    std::vector<Account *> accounts(4);

    accounts[0] = new SavingsAccount(25.0, .03);
    accounts[1] = new CheckingAccount(80.0, 1.0);
    accounts[2] = new SavingsAccount(200.0, .015);
    accounts[3] = new CheckingAccount(400.0, .5);

    std::cout << std::fixed << std::setprecision(2);

    for (size_t i = 0; i < accounts.size(); ++i)
    {
        std::cout << "Account " << i + 1 << " balance: $"
                  << accounts[i]->getBalance();

        double withdrawalAmount = 0.0;

        std::cout << "\nEnter an amount to withdraw from Account " << i + 1
                  << ": ";
        std::cin >> withdrawalAmount;

        accounts[i]->debit(withdrawalAmount);

        double depositAmount = 0.0;

        std::cout << "Enter an amount to deposit into Account " << i + 1
                  << ": ";
        std::cin >> depositAmount;
        accounts[i]->credit(depositAmount);

        SavingsAccount *savingsAccountPtr = dynamic_cast<SavingsAccount *>(accounts[i]);

        if (savingsAccountPtr != 0)
        {
            double interestEarned = savingsAccountPtr->calculateInterest();
            std::cout << "Adding $" << interestEarned << " interest to Account "
                      << i + 1 << " (a SavingsAccount)" << std::endl;
            savingsAccountPtr->credit(interestEarned);
        }

        std::cout << "Updated Account " << i + 1 << " balance: $" << accounts[i]->getBalance() << "\n\n";
    }

    return 0;
}
