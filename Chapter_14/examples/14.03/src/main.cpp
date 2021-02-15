#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::ofstream outClientFile("clients.txt", std::ios::out);

    if (!outClientFile)
    {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter the account, name and balance." << std::endl
              << "Enter end-of-file to end input.\n? ";

    int account;
    std::string name;
    double balance;

    while ( std::cin >> account >> name >> balance)
    {
        outClientFile << account << ' ' << name << ' ' << balance << std::endl;
        std::cout << "? ";
    }

    return 0;
}
