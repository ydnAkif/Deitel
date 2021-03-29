#include <iostream>

class ExceptionClass
{
private:
    std::string message;

public:
    ExceptionClass() : message("An exception was thrown")
    {
    }

    void print() const
    {
        std::cerr << std::endl
                  << message << std::endl;
    }
};

void generateException();

int main(int argc, char const *argv[])
{
    try
    {
        generateException();
    }
    catch (...)
    {
        std::cerr << "The \"catch all\" exception handler was invoked\n";
    }

    return 0;
}

void generateException()
{
    throw ExceptionClass();
}
