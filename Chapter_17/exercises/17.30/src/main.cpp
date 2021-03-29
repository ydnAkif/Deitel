#include <iostream>

class TestException1
{
private:
    std::string message;

public:
    TestException1(std::string m) : message(m) {}
    void print() const { std::cerr << message << std::endl; }
};

class TestException2
{
private:
    std::string message;

public:
    TestException2(std::string m) : message(m) {}
    void print() const { std::cerr << message << std::endl; }
};

void f() { throw TestException1("TestException 1"); }

void g()
{
    try
    {
        f();
    }
    catch (TestException2 &t2)
    {
        std::cerr << "In g: Caught ";
        t2.print();
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        g();
    }
    catch (TestException1 &t1)
    {
        std::cerr << "In main: Caught ";
        t1.print();
    }

    return 0;
}
