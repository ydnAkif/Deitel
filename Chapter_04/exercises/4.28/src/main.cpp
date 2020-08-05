#include <iostream>



int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 8; ++i)
    {
        if (i%2 !=0)
        {
            std::cout << " ";
        }
        for (size_t j = 0; j < 8; ++j)
        {
            std::cout << "*";
        }
        std::cout<<std::endl;

    }


    return 0;
}

