#include <iostream>

int main()
{
    int rows{0};

    std::cout << "Enter an odd number of rows to display: 1-19:(-1 to quit) ";
    std::cin >> rows;
    while (rows != -1)
    {
        if (rows <= 19 && rows >= 1 && rows % 2 != 0)
        {
            for (int i{1}, j{1}, k{rows / 2}; i <= rows; ++i)
            {
                for (int s{0}; s < k; ++s)
                {
                    std::cout << " ";
                }

                for (int d{0}; d < j; ++d)
                {
                    std::cout << "*";
                }

                (i > rows / 2) ? j -= 2 : j += 2;
                (i > rows / 2) ? k++ : k--;

                std::cout << std::endl;
            }
        }
        else
        {
            std::cout << std::endl
                      << "Incorrect odd number !!!"
                      << std::endl;
        }
        std::cout << std::endl
                  << "Enter an odd number of rows to display: 1-19:(-1 to quit) ";
        std::cin >> rows;
    }

    return 0;
}