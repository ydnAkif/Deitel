#include "SalaryCalculator.hpp"

static const int QUIT = -1;

int main(int argc, char const *argv[])
{
    SalaryCalculator sc;

    while (sc.getHourWorked() != QUIT)
    {
        sc.run();
    }

    return 0;
}
