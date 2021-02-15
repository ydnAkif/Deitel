#include <iostream>
#include <fstream>
#include <cstdlib>

#include "ClientData.hpp"

int main(int argc, char const *argv[])
{
    int accountNumber;
    std::string lastName;
    std::string firstName;
    double balance;

    std::fstream outCredit("../credit.dat", std::ios::in | std::ios::out | std::ios::binary);

    if (!outCredit)
    {
        std::cerr << "File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter account number (1 to 100, 0 to end input)\n?";

    ClientData client;

    std::cin >> accountNumber;

    while (accountNumber > 0 & accountNumber <= 100)
    {
        std::cout << "Enter lastname, firstname, balance\n? ";
        std::cin >> lastName;
        std::cin >> firstName;
        std::cin >> balance;

        client.setAccountNumber(accountNumber);
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);

        outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));

        outCredit.write(reinterpret_cast<const char *>(&client), sizeof(ClientData));

        std::cout << "Enter account number\n? ";
        std::cin >> accountNumber;
    }

    return 0;
}
