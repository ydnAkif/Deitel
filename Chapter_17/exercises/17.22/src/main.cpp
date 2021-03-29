#include <iostream>
#include <cstdlib>
#include <ctime>

class BaseException
{
public:
    BaseException(std::string m) : message(m) {}
    void print() const
    {
        std::cout << message << std::endl;
    }

private:
    std::string message;
};

class DerivedException : public BaseException
{
public:
    DerivedException(std::string m) : BaseException(m) {}
};

class DerivedException2 : public DerivedException
{
public:
    DerivedException2(std::string m) : DerivedException(m) {}
};

int main(int argc, char const *argv[])
{
    srand(time(0));

    try
    {
        throw(rand() % 2 ? DerivedException("Derived Exception") : DerivedException2("Derived Exception 2"));
    }
    catch (BaseException &b)
    {
        b.print();
    }

    return 0;
}
