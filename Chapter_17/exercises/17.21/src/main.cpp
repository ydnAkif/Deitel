#include <iostream>
#include <string>

class TestException
{
public:
    TestException(std::string m)
        : message(m)
    {
    }

    void print() const
    {
        std::cout << message << std::endl;
    }

private:
    std::string message;
};

int main(int argc, char const *argv[])
{
    try
    {
        throw TestException("This is a test");
    }
    catch (TestException &t)
    {
        t.print();
        throw TestException("This is another test");
    }

    return 0;
}
