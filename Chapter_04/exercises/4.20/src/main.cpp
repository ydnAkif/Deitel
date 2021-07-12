/******************************************************************************

Exercises 4.20

(Validating User Input) The examination-results program of Fig. 4.16 assumes 
that any val- ue input by the user that’s not a 1 must be a 2. Modify the 
application to validate its inputs. On any input, if the value entered is other 
than 1 or 2, keep looping until the user enters a correct value.

******************************************************************************/

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