#include <iostream>

template <typename T>

T minimum(T num1, T num2)
{
    return (num1 < num2) ? num1 : num2;
}
int main()
{

    std::cout << "Template testing using int, char and float"
              << std::endl;

    //int

    std::cout << "minimum(91, 78): "
              << minimum(91, 78)
              << std::endl;

    //char

    std::cout << "minimum(x, G): "
              << minimum('x', 'G')
              << std::endl;

    //int double
    std::cout << "minimum(61.25, 68.5): "
              << minimum(61.25, 68.5)
              << std::endl;

    return 0;
}
