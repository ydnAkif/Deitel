#include <iostream>

class TestException
{
    private:
        std::string message;
    public:
        TestException(std::string m) : message(m) {}
        void print() const { std::cerr << message << std::endl; }
};

void f() { throw TestException("Test exception thrown"); }

void g()
{
    try
    {
        f();
    }
    catch(...)
    {
        std::cerr << "Exception caught in function g(). Rethrowing...\n";
        throw;
    }
    
}

int main(int argc, char const *argv[])
{
    try
    {
        g();
    }
    catch(...)
    {
        std::cerr << "Exception caught in function main()\n";
    }
    
    return 0;
}
