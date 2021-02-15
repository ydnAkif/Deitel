#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

enum RequestType
{
    ZERO_BALANCE = 1,
    CREDIT_BALANCE,
    DEBIT_BALANCE,
    END
};

int getRequest();
bool shouldDisplay(int, double);
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

    int request = getRequest();

    while (request != RequestType::END)
    {
        switch (request)
        {
        case RequestType::ZERO_BALANCE:
            std::cout << "\nAccounts with zero balances:\n ";
            break;
        case RequestType::CREDIT_BALANCE:
            std::cout << "\nAccounts with credit balances:\n";
            break;
        case RequestType::DEBIT_BALANCE:
            std::cout << "\nAccounts with debit balances:\n";
            break;
        }

        inClientFile >> account >> name >> balance;

        while (!inClientFile.eof())
        {
            if (shouldDisplay(request, balance))
                outputLine(account, name, balance);

            inClientFile >> account >> name >> balance;
        }

        inClientFile.clear();
        inClientFile.seekg(0);
        request = getRequest();
    }

    std::cout << "End of run." << std::endl;

    return 0;
}

int getRequest()
{
    int request;

    std::cout << "\nEnter request" << std::endl
              << "1- List accounts with zero balances" << std::endl
              << "2- List accounts with credit balances" << std::endl
              << "3- List accounts with debit balances" << std::endl
              << "4- End of run" << std::fixed << std::showpoint;

    do
    {
        std::cout << "\n?";
        std::cin >> request;

    } while (request<RequestType::ZERO_BALANCE & request> RequestType::END);

    return request;
}

bool shouldDisplay(int type, double balance)
{
    if (type == RequestType::ZERO_BALANCE && balance == 0)
        return true;

    if (type == RequestType::CREDIT_BALANCE && balance < 0)
        return true;

    if (type == RequestType::DEBIT_BALANCE && balance > 0)
        return true;

    return false;
}

void outputLine(int account, const std::string &name, double balance)
{
    std::cout << std::left << std::setw(10) << account
              << std::setw(13) << name
              << std::setw(7) << std::setprecision(2)
              << std::right << balance << std::endl;
}
