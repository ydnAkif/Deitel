#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.hpp"

int main(int argc, char const *argv[])
{
    std::ofstream outCredit("../credit.dat", std::ios::out | std::ios::binary);

    if (!outCredit)
    {
        std::cerr << "File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    }

    ClientData blankClient;

    for (int i = 0; i < 100; ++i)
        outCredit.write(reinterpret_cast<const char *>(&blankClient), sizeof(ClientData));

    return 0;
}
