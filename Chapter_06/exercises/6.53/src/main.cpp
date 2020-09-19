#include <iostream>

template <typename T>
T maximum(T num1, T num2)
{
    return (num1 > num2) ? num1 : num2;
}
int main()
{
    std::cout << "Template testing using int, char and float"
              << std::endl;
    std::cout << "maximum(91, 78): "
              << maximum(91, 78)
              << std::endl;

    //char

    std::cout << "maximum(x, G): "
              << maximum('x', 'G')
              << std::endl;

    //int double
    std::cout << "maximum(61.25, 68.5): "
              << maximum(61.25, 68.5)
              << std::endl;
    return 0;
}
