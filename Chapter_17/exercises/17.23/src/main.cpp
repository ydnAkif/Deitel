#include <iostream>

int main(int argc, char const *argv[])
{
    try
    {
        int a = 7;
        double b = 9.9;
        throw a < b ? a : b;
    }
    catch (int x)
    {
        std::cerr << "The int value " << x << " was thrown\n";
    }
    catch (double y)
    {
        std::cerr << "The double value " << y << " was thrown\n";
    }

    return 0;
}
