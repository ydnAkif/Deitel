#include <iostream>
#include <new>
#include <cstdlib>

void customNewHandler()
{
    std::cerr << "customNewHandler() was called.";
    abort();
}

int main(int argc, char const *argv[])
{

    double *ptr[50];

    std::set_new_handler(customNewHandler);

    for (size_t i = 0; i < 50; ++i)
    {
        ptr[i] = new double[500'000'000];
        std::cout << "ptr[" << i << "] points to 500,000,000 new doubles\n";
    }

    return 0;
}
