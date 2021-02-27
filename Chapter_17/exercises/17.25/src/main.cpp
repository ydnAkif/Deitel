#include <iostream>

class ExceptionClass
{
private:
    std::string message;

public:
    ExceptionClass() : message("An exception was thrown") {}
    void print() const
    {
        std::cerr << std::endl
                  << message << std::endl;
    }
};

class Member
{
private:
    int value;

public:
    Member(int val) : value(val)
    {
        std::cout << "Member object " << value << " constructor called.\n";

        if (value == 3)
            throw ExceptionClass();
    }
    ~Member()
    {
        std::cout << "Member object " << value << " destructor called.\n";
    }
};

class Encapsulate
{
private:
    Member m1, m2, m3, m4, m5;

public:
    Encapsulate() : m1(1), m2(2), m3(3), m4(4), m5(5)
    {
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "Constructoring an object of class Encapsulate\n";

    try
    {
        Encapsulate e;
    }
    catch (ExceptionClass &except)
    {
        except.print();
    }

    return 0;
}
