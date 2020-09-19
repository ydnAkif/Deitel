#include <iostream>

inline int tripleByValue(int count)
{
    count = count * count * count;
    return count;
}

inline int tripleByReference(int &count)
{
    count = count * count * count;
    return count;
}

int main()
{
    std::cout << "Demonstrating passing parameters by reference and value"
              << std::endl;

    int count = 3;

    tripleByValue(count);

    std::cout << "tripleByValue = "
              << count
              << std::endl;

    tripleByReference(count);
    std::cout
        << "tripleByReference = "

        << count
        << std::endl;

    return 0;
}
