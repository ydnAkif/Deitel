#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

void outputLine(int, const std::string &, double);

int main(int argc, char const *argv[])
{
    std::ifstream inClientFile("../clients.txt", std::ios::in);

    if (!inClientFile)
    {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    int account;
    std::string name;
    double balance;

    std::cout << std::left << std::setw(10) << "Account" << std::setw(13)
              << "Name" << std::setw(7)
              << "Balance" << std::endl
              << std::fixed << std::showpoint;

    while (inClientFile >> account >> name >> balance)
    {
        outputLine(account, name, balance);
    }

    return 0;
}

void outputLine(int account, const std::string &name, double balance)
{
    std::cout << std::left << std::setw(10) << account << std::setw(13) << name
              << std::setw(7) << std::setprecision(2) << std::right << balance << std::endl;
}