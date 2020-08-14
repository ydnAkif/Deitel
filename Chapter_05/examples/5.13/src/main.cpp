#include <iostream>

int main()
{
    unsigned int counter{1};

    for (counter = 1; counter <= 10; ++counter)
    {
        if (counter == 5)
        {
            break;
        }

        std::cout << counter << " ";
    }
    std::cout << "\nBroke out of loop at counter = " << counter << std::endl;

    return 0;
}