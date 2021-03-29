#include <iostream>
#include <new>

int main(int argc, char const *argv[])
{
    double *ptr[50];

    try
    {
        for (size_t i = 0; i < 50; ++i)
        {
            ptr[i] = new double[500000000];
            std::cout << "ptr[" << i << "] points to 500,000,000 new doubles\n";
        }
    }
    catch (std::bad_alloc &memoryAllocationException)
    {
        std::cerr << "Exceptiron occurred: " << memoryAllocationException.what() << std::endl;
    }

    return 0;
}
