#include "CreditLimits.hpp"

const static int QUIT = -1;

int main(int argc, char const *argv[])
{
    CreditLimits cl1;

    while (cl1.getAccountNumber() != QUIT)
    {
        cl1.run();
    }

    return 0;
}
