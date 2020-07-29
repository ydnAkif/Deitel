#include <iostream>
#include <iomanip>
int main()
{
    unsigned int passes{0}, failures{0}, studentCounter{0};
    int result{0};

    while (++studentCounter <= 10)
    {
        std::cout << "Enter result (1 = pass, 2 = fail): ("
                  << std::setw(2)
                  << (10 - (studentCounter - 1))
                  << " remaining): ";

        std::cin >> result;

        if (result == 1)
        {
            ++passes;
        }
        else if (result == 2)
        {
            ++failures;
        }
        else
        {
            --studentCounter;
            continue;
        }
    }

    std::cout << "Passed "
              << passes
              << "\nFailed "
              << failures
              << std::endl;

    if (passes > 8)
    {
        std::cout << "Bonus to instructor!"
                  << std::endl;
    }

    return 0;
}