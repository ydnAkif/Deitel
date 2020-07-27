#include "SalesCommissionCalculator.hpp"

static const int QUIT = -1;

int main(int argc, char const *argv[])
{
    SalesCommissionCalculator scc;
    while (scc.getWeeklySales() != QUIT)
    {
        scc.run();
    }

    return 0;
}
