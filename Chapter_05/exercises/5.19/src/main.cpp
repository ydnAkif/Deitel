#include <iostream>
#include <iomanip>

int main()
{
    int toogle{0};
    int limit{1000};

    double pi{4.0f};
    double divisor{3.0f};

    std::cout << std::setw(4)
              << "Term"
              << std::setw(13)
              << "PI Aproax"
              << std::endl;

    for (int i = 1; i <= limit; ++i)
    {
        toogle == 0 ? (pi -= (4.0f / divisor)) : (pi += (4.0f / divisor));

        toogle = (1 - toogle);

        divisor += 2;

        std::cout << std::setw(4)
                  << i
                  << std::setw(13)
                  << std::fixed
                  << std::setprecision(6)
                  << pi
                  << std::endl;
    }

    return 0;
}