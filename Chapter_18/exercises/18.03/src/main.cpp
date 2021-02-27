#include <iostream>
#include <typeinfo>

template <typename T>
bool isEqualTo(const T &arg1, const T &arg2) { return arg1 == arg2; }

class SomeClass
{
    friend std::ostream &operator<<(std::ostream &, SomeClass &);

public:
    SomeClass(int s, double t)
    {
        x = s;
        y = t;
    }

    bool operator==(const SomeClass &right) const
    {
        return x == right.x && y == right.y;
    }

private:
    int x;
    double y;
};

std::ostream &operator<<(std::ostream &output, SomeClass &obj)
{
    output << '(' << obj.x << ", " << obj.y << ')';
    return output;
}

template <typename T>
void testPrint(T &firstValue, T &secondValue)
{
    T first = firstValue;
    T second = secondValue;

    std::cout << "Enter two values: ";
    std::cin >> first >> second;

    std::cout << first << " and  " << second << " are "
              << (isEqualTo(first, second) ? "equal" : "not equal") << std::endl;
}

int main(int argc, char const *argv[])
{
    int a, b;
    testPrint(a, b);

    char c, d;
    testPrint(c, d);

    double e, f;
    testPrint(e, f);

    SomeClass g(1, 1.1), h(1, 1.1);

    std::cout << "\nThe class objects " << g << " and " << h << " are "
              << (isEqualTo(g, h) ? "equal" : "not equal") << std::endl;

    return 0;
}
