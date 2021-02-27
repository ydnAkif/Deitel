#include <iostream>

class TestException
{
private:
    std::string message;

public:
    TestException(std::string m) : message(m) {}
    void print() const
    {
        std::cout << message << std::endl;
    }
};

void f() { throw TestException("TestException"); }

void g() { f(); }

void h() { g(); }

int main(int argc, char const *argv[])
{
    try
    {
        h();
    }
    catch (TestException &t)
    {
        std::cerr << "In main: Caught ";
        t.print();
    }

    return 0;
}
