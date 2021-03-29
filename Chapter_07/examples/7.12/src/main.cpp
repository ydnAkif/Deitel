#include <iostream>
#include <array>

void staticArrayInit();
void automaticArrayInit();

const size_t arraySize = 3;

int main()
{
    std::cout << "First call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    std::cout << "\n\nSecond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    std::cout << std::endl;
}

void staticArrayInit(void)
{
    static std::array<int, arraySize> array1;
    std::cout << "\nValues on entering staticArrayInit:\n";

    for (size_t i = 0; i < array1.size(); ++i)
    {
        std::cout << "array1[" << i << "] = " << array1[i] << " ";
    }

    std::cout << "\nValues on exiting staticArrayInit:\n";

    for (size_t j = 0; j < array1.size(); ++j)
    {
        std::cout << "array1[" << j << "] = " << (array1[j] +=5 )<< " ";
    }
    
}

void automaticArrayInit(void)
{
    std::array<int, arraySize> array2 = {1,2,3};
    std::cout << "\n\nValues on entering automaticArrayInit:\n";

    for (size_t i = 0; i < array2.size(); ++i)
    {
        std::cout << "array2[" << i << "] = " << array2[i] << " ";
    }

    std::cout << "\nValues on exiting automaticArrayInit:\n";

    for (size_t j = 0; j < array2.size(); ++j)
    {
        std::cout << "array2[" << j << "] = " << (array2[j] +=5 )<< " ";
    }
    
}